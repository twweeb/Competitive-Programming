//
//  function.cpp
//  (#11460) string exam
//
//  Created by Magic Bear on 2018/1/2.
//  Copyright © 2018年 Magic Bear. All rights reserved.
//

#include "function.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

void ParseString( const string& aLine, vector< string>& tokens ){
    string buffer;
    stringstream ss( aLine);
    while( ss >> buffer )
        tokens.push_back( buffer );
}
std::string string_change_order(const std::string &str)
//change string order and add "ay" to word if the first character of word is vowel(a e i o u A E I O U)
{
    int i = 0;
    string new_message = "";
    vector<string> Tokens;
    Tokens.clear();
    ParseString( str, Tokens );
    vector<string>::iterator itr;
    
    string alphabet = "AEIOUaeiou";
    for( i = 0, itr = Tokens.end()-1; i<Tokens.size(); i++, itr-- ){
        string AWord = *itr;
        for( int j = 0; j < alphabet.length(); j++ ){
            if( AWord[0] == alphabet[ j ] ){
                AWord += "ay";
            }
        }
        if(itr!=Tokens.begin()) AWord += " ";
        new_message += AWord;
    }
    return new_message;
}

