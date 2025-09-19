class Spreadsheet {
    int getNum(string s,int i) {
        int num = 0;
        int n = s.length();
        while(i < n) {
            int d = s[i]-'0';
            num = num*10 + d;
            i++;
        }
        return num;
    }

    vector<int> getCell(string cell) {
        char ch = cell[0];
        int col = ch-'A';
        int row = getNum(cell,1);
        return {row,col};
    }

    vector<vector<int>> spreadSheet;

public:

    Spreadsheet(int rows) {
        spreadSheet.resize(rows+1);
        for(int i=0;i<rows+1;i++) {
            spreadSheet[i].resize(26);
        }
    }
    
    void setCell(string cell, int value) {
        vector<int> d = getCell(cell);
        spreadSheet[d[0]][d[1]] = value;
    }
    
    void resetCell(string cell) {
        vector<int> d = getCell(cell);
        spreadSheet[d[0]][d[1]] = 0;
    }
    
    int getValue(string formula) {
        string x = "";
        int i = 1;
        int n = formula.length();
        while(i < n && formula[i] != '+') {
            x += formula[i];
            i++;
        }
        i++;
        string y = "";
        while(i < n) {
            y += formula[i];
            i++;
        }

        int X,Y;
        if(isdigit(x[0])) {
            X = getNum(x,0);
        }
        else {
            vector<int> d = getCell(x);
            X = spreadSheet[d[0]][d[1]];
        }

        if(isdigit(y[0])) {
            Y = getNum(y,0);
        }
        else {
            vector<int> d = getCell(y);
            Y = spreadSheet[d[0]][d[1]];
        }

        return X+Y;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */