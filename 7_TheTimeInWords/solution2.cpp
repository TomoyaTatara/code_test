#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'timeInWords' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. INTEGER h
 *  2. INTEGER m
 */

string numToWords(int n) {
    
    string num[21]={
                    "one",
                    "two",
                    "three",
                    "four",
                    "five",
                    "six",
                    "seven",
                    "eight",
                    "nine",
                    "ten",
                    "eleven",
                    "twelve",
                    "thirteen",
                    "fourteen",
                    "quarter",
                    "sixteen",
                    "seventeen",
                    "eighteen",
                    "nineteen",
                    "twenty",
                    "half"
    };

    if (n<=20) {
        return num[n-1];
    }
    else if (n==30) {
        return num[20];
    }
    
    return num[19] + " " + num[n-21];
}

string timeInWords(int h, int m) {
    string res;
    
    if (m==0) {
        return numToWords(h) + " o' clock";
    }
    if (m==15||m==30) {
        return numToWords(m) + " past " + numToWords(h);
    }
    if (m==1) {
        return numToWords(m) + " minute past " + numToWords(h);
    }
    if (m<=30) {
        return numToWords(m) + " minutes past " + numToWords(h);
    }
    if (m==45) {
        return numToWords(60-m) + " to " + numToWords(h+1);
    }
    if (m==59) {
            return numToWords(60-m) + " minute to " + numToWords(h+1);
    }
    return numToWords(60-m) + " minutes to " + numToWords(h+1);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string h_temp;
    getline(cin, h_temp);

    int h = stoi(ltrim(rtrim(h_temp)));

    string m_temp;
    getline(cin, m_temp);

    int m = stoi(ltrim(rtrim(m_temp)));

    string result = timeInWords(h, m);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
