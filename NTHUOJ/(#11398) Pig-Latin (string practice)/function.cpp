//
//  function.cpp
//  (#11398) Pig-Latin (string practice)
//
//  Created by Magic Bear on 2017/12/22.
//  Copyright © 2017年 Magic Bear. All rights reserved.
//

#include "function.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

void replace(string& str, const string& from, const string& to) {
    size_t start_pos = str.find(from);
    if(start_pos == string::npos) return;
    str.replace(start_pos, from.length(), to);
}

void ParseString( const string& aLine, vector< string>& tokens ){
    string buffer;
    stringstream ss( aLine);
    while( ss >> buffer )
        tokens.push_back( buffer );
}

string string_replace(string str, const string &s1, const string &s2){
    replace(str, s1, s2);
    return str;
}

string string_change_word(string message){
    bool bFoundVowel = false;
    int
    i = 0,
    j = 0;
    
    string
    new_word = "",
    pig_message = "",
    vowels = "aeiouAEIOU";
    
    vector< string > Tokens;
    Tokens.clear();
    ParseString( message, Tokens );
    vector< string >::iterator itr;
    
    for( i = 0, itr = Tokens.begin(); itr != Tokens.end(); i++, itr++ ){
        string AWord = *itr;
        bFoundVowel = false;
        
        for( j = 0; j < vowels.length(); j++ ){
            if( tolower( AWord[ 0 ] ) == vowels[ j ] ){
                bFoundVowel = true;
                new_word = AWord + "ay ";
                pig_message += new_word;
                break;
            }       /*      If we found a vowel     */
        }       /*      for( j < vowels.length() )      */
        
        if( ! bFoundVowel ){
            new_word = AWord.substr( 1 );
            new_word += AWord[ 0 ];
            new_word += "ay ";
            pig_message += new_word;
        }       /*      if( ! bFoundVowel )     */
    }       /*      for( itr != Tokens.end() )      */
    return pig_message;
}
