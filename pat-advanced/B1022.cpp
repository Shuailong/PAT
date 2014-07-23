/*
 * B1022.cpp
 * 
 * Copyright 2014 Liangshuailong <zju_shuailong@163.com>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */
#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;
int main(int argc, char **argv)
{
    int N;
    cin >> N;
    getchar();
    map<string, vector<string> > titleinfo;
    map<string, vector<string> > authorinfo;
    map<string, vector<string> > keywordsinfo;
    map<string, vector<string> > publisherinfo;
    map<string, vector<string> > yearinfo;

    string id, title, author, keywords, publisher, year;

    for(int i = 0; i < N; ++i){
        getline(cin, id);
        getline(cin, title);
        getline(cin, author);
        getline(cin, keywords);
        getline(cin, publisher);
        getline(cin, year);
        
        vector<string> ids = titleinfo[title];
        ids.push_back(id);
        titleinfo[title] = ids;
        
        ids = authorinfo[author];
        ids.push_back(id);
        authorinfo[author] = ids;

        stringstream ss(keywords);
        string keyword;
        while(!ss.eof()){
            ss >> keyword;
            ids = keywordsinfo[keyword];
            ids.push_back(id);
            keywordsinfo[keyword] = ids;
        }
        
        ids = publisherinfo[publisher];
        ids.push_back(id);
        publisherinfo[publisher] = ids;

        ids = yearinfo[year];
        ids.push_back(id);
        yearinfo[year] = ids;        
    }
    
    int M;
    cin >> M;
    getchar();

    for(int i = 0; i < M; ++i){
        string query;
        getline(cin, query); 
        string name = query.substr(3);
        
        vector<string> ids;
        switch(query[0]){
            case '1':
                ids = titleinfo[name];
                break;
            case '2': 
                ids = authorinfo[name];
                break;
            case '3':
                ids = keywordsinfo[name];
                break;
            case '4':
                ids = publisherinfo[name];
                break;
            case '5':
                ids = yearinfo[name];
                break;
            default: break;
        }
        
        cout << query << endl;
        if(ids.empty()){
            cout << "Not Found" << endl;
        }
        else{
            sort(ids.begin(), ids.end());
            for(size_t j = 0; j < ids.size(); ++j){
                cout << ids[j] << endl;
            }
        }
    }

    return 0;
}

