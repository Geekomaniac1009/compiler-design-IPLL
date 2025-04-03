
#include <bits/stdc++.h>
using namespace std;

int LOCCTR = 0;
int progLen = 0;
int initAddress = 0;

map <string, int> SYMTAB; 
map <string, string> OPTAB; 

// String parsing functions: appending spaces at front and end of the string
void append(string& s, int size, char space) {
    reverse(s.begin(), s.end());
    while(s.length() < size){
        s.push_back(space);
    }
    reverse(s.begin(), s.end());
    return;
}

void extend(string& s, int size, char space) {
    while(s.length() < size) {
        s.push_back(space);
    }
    return;
}

// Conversion functions
int hexConvert(string operand){
    int res = 0;
    long long pow = 1;
    for(int i= operand.length()-1; i>=0; i--){
        if(operand[i] <= '9' && operand[i] >= '0'){
            res += pow*(operand[i]-'0');
        }
        else if(operand[i] >= 'A' && operand[i] <= 'F'){
            res += pow*(operand[i]-'A'+10);
        }
        else{
            cout << "Error encountered in hex conversion" << endl;
            return -1;
        }
        pow *= 16;
    }
    return res;
}

int intConvert(string& s) {
    int res = 0;
    long long pow = 1;
    for(int i = s.length()-1; i >= 0; --i) {
        if(s[i] >= '0' && s[i] <= '9'){
            res += pow*(s[i]-'0');
        }
        else{
            cout << "Error encountered in decimal conversion" << endl;
        }
    }
    return res;
}


string hexNotation(int n){
    string res = "";
    while(n){
        if(n%16 >= 10){
            res += char('A' + n%16 - 10);
        }
        else{
            res += char('0' + n%16);
        }
        n/= 16;
    }
    reverse(res.begin(), res.end());
    return res;
}

// Separating words separated by spaces on a line
vector <string> split_parser(int index, string& data) {
    int counter = 0;
    vector <string> res;
    res.resize(3, "");

    if(data[0] == '.') {
        res[0] = ".";
        return res;
    }
    for(int i = index; i<data.length(); i++) {
        if(data[i] != ' ') {
            res[counter] += (data[i]);
        }
        else {
            while(data[i] == ' '){
                i++;
                if(i == data.length()){
                    break;
                }
            }
            counter++;
            i--;
        }
    }
    return res;
}

// Precomputing the optable as given before initialising the passes
void populateOpTable(){
    ifstream input("opcodes.txt");
    ofstream optab("optable.txt");
    string data;

    while(getline(input, data)) {
        string opcode;
        string hex;
        vector <string> ans = split_parser(0, data);
        opcode = ans[0];
        hex = ans[1];
        OPTAB[opcode] = hex;
    }

    // verifying if optable has been correctly populated
    for(auto it: OPTAB){
        string temp = it.first;
        extend(temp, 10, ' ');
        optab << temp << "  " << it.second << endl;
    }
}

// Handling data constants specified in source prog
string generate(string &s) {
    string res = "";
    char check = toupper(s[0]);
    if((check == 'C' || check == 'X') && s[1] == '\'') {
        for(int i = 2; i < s.length(); i++) {
            if(s[i] == '\'') {
                break;
            }
            res += hexNotation(int(s[i]));
        }
        return res;
    }
    res = hexNotation(intConvert(s));
    append(res, 6, '0');
    return res;
}

int byteLen(string& s) {
    int ans = 0;
    char check = toupper(s[0]);
    if((check == 'C' || check == 'X') && s[1] == '\'') {
        for(int i = 2; i < s.length(); i+=2) {
            if(s[i] == '\'') {
                break;
            }
            else{
                ans++;
            }
        }
    }
    return ans;
}

// first pass
void pass1() {
    cout << "Initialising pass 1..." << endl;

    ifstream input("sample_input.txt");
    ofstream intermediate("intermediate.txt");
    ofstream symtab("symtable.txt");

    string data;
    bool start_found = false;

    while(getline(input, data)) {
        string label;
        string opcode;
        string operand;
        
        vector <string> ans = split_parser(0, data);
        label = ans[0];
        opcode = ans[1];
        operand = ans[2];
        
        // Ignore comments in the assembly code
        if(label == ".") {
            intermediate << data << endl;
            continue;
        }
        if(!start_found){
            LOCCTR = 0;
        }
        if(opcode == "START") {
            LOCCTR = hexConvert(operand);
            progLen = LOCCTR;
            initAddress = LOCCTR;
            extend(operand, 5, ' ');
            operand += data;
            intermediate << operand << endl;
            start_found = true;
            if(label != "") {
                SYMTAB[label] = LOCCTR;
            }
            continue;
        }
    
        if(opcode == "END") {
            string res = hexNotation(LOCCTR);
            extend(operand, 5, ' ');
            intermediate << res << data << endl;
            break;
        }

        if(label != "") {
            if(SYMTAB.find(label) != SYMTAB.end()) {
                cout << "Duplicate label: " << label << "found" << endl;
                break;
            } 
            else {
                SYMTAB[label] = LOCCTR;
            }
        }

        string res = hexNotation(LOCCTR);
        extend(res, 5, ' ');
        res += data;
        intermediate << res << endl;

        if(OPTAB.find(opcode) != OPTAB.end()) {
            LOCCTR += 3;
        } 
        else if(opcode == "WORD") {
            LOCCTR += 3;
        } 
        else if(opcode == "RESW") {
            LOCCTR += (3 * intConvert(operand));
        } 
        else if(opcode == "RESB") {
            LOCCTR += intConvert(operand);
        } 
        else if(opcode == "BYTE") {
            LOCCTR += byteLen(operand);
        } 
        else {
            cout << "Wrong value of opcode!" << endl;
            break;
        }
    }

    progLen = LOCCTR - progLen;

    // verifying if the symbol table is populated correctly 
    for(auto it: SYMTAB){
        string temp = it.first;
        extend(temp, 10, ' ');
        symtab << temp << "     " << hexNotation(it.second) << endl;
    }

    input.close();
    intermediate.close();
    symtab.close();

    cout << "Pass 1 completed!" << endl;
}

// second pass
void pass2() {
    progLen = 0;
    initAddress = 0;
    cout << "Initialising pass 2..." << endl;

    ifstream intermediate("intermediate.txt");
    ofstream source("source.txt");
    ofstream output("output.txt");

    string data;
    string recText = "";
    string startLoc = "";
    string header = " ^     ^ ";
    string rdLine = header;
  
    while(getline(intermediate, data)) {  
        
        string objectCode = "";
        string label;
        string opcode;
        string operand;

        string track = data.substr(0, 4);

        vector<string> ans = split_parser(5, data);
        label = ans[0];
        opcode = ans[1];
        operand = ans[2];
        
        if(data[0] == '.') {
            source << data << endl;
            continue;
        }

        if(opcode == "START") {
            source << data << endl;
            extend(label, 6, ' ');
            append(operand, 6, '0');

            string len = hexNotation(progLen);
            append(len, 6, '0');
           
            output << "H" << label << operand << len << endl;
            output << " ^     ^     ^" << endl;
            startLoc = operand;
            continue;
        }

        if(opcode == "END") {
            source << data << endl;
            if(recText.length()) {
                append(startLoc, 6, '0');
                string hexSize = hexNotation(recText.length() / 2);
                append(hexSize, 2, '0');
                recText = "T" + startLoc + hexSize + recText;
                
                output << recText << endl;
                output << rdLine << endl;
            }
            
            string end = hexNotation(initAddress);
            append(end, 6, '0');
            recText = "E" + end;
           
            output << recText << endl;
            output << " ^" << endl;
            break;
        }

        if(OPTAB.find(opcode) != OPTAB.end()) {
            if(SYMTAB.find(operand) != SYMTAB.end()) {
                objectCode = OPTAB[opcode] + hexNotation(SYMTAB[operand]);
            }
            else if(operand == "BUFFER,X") {
                objectCode = OPTAB[opcode] + hexNotation(SYMTAB["BUFFER"] + hexConvert("8000"));
            }
            else{
                objectCode = OPTAB[opcode];
                extend(objectCode, 6, '0');
            }
        }
        else if(opcode == "BYTE" || opcode == "WORD") {
            objectCode = generate(operand);
        }

        extend(data, 30, ' ');
        data += objectCode;
        source << data << endl;

        if(startLoc == "" && objectCode != "") {
            startLoc = track;
        }

        int word_len = recText.length();
        int obj_len = objectCode.length();

        if((obj_len == 0) || (word_len + obj_len > 60)) {
            
            if(word_len == 0) {
                continue;
            }

            append(startLoc, 6, '0');

            string hexSize = hexNotation(word_len/2);
            append(hexSize, 2, '0');

            recText = "T" + startLoc + hexSize + recText;
           
            output << recText << endl;
            output << rdLine << endl;

            recText = objectCode;
            rdLine = header;
            startLoc = "";

            if(obj_len) {
                startLoc = track;
                rdLine = header;
                rdLine.push_back('^');
                extend(rdLine, rdLine.length() + obj_len - 1, ' ');
            }
        }
        else if(obj_len) {
            recText += objectCode;
            rdLine.push_back('^');
            extend(rdLine, rdLine.length() + obj_len - 1, ' ');
        }
    }

    intermediate.close();
    source.close();
    output.close();

    cout << "Pass 2 completed!" << endl;
}

int main() {
    populateOpTable();
    pass1();
    pass2();
}