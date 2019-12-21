//
//  breadthFirstSearch.hpp
//  Dat_Structure
//
//  Created by  云子谣 on 2019/12/18.
//  Copyright © 2019  云子谣. All rights reserved.
//

#ifndef breadthFirstSearch_hpp
#define breadthFirstSearch_hpp

#include <stdio.h>
#include <map>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>
class breadthFirstSearch
{
public:
    
    breadthFirstSearch();
    ~breadthFirstSearch();
    std::map<std::string, std::vector<std::string>> graph;//图结构
    //me's relationship
    
    std::pair<std::string, std::vector<std::string>> me;
    //1DRelationship
    //bob's relationship
    
    std::pair<std::string, std::vector<std::string>> bob;
    
    //claire's relationship
    
    std::pair<std::string, std::vector<std::string>> claire;
    //alice's relationship
    
    std::pair<std::string, std::vector<std::string>> alice;
    
    //2DRelationship
    //anuj,peggy,thom,jonny
    std::pair<std::string, std::vector<std::string>> anuj;
    std::pair<std::string, std::vector<std::string>> peggy;
    std::pair<std::string, std::vector<std::string>> thom;
    std::pair<std::string, std::vector<std::string>> jonny;

    
    std::queue<std::vector<std::string> > q;
    //std::map< std::string, std::vector<std::string> > graph;
    //std::queue<>
    std::queue<std::string > q_s;
    
    
    
    
    bool findSeller();
    
    
    bool PersonIsSeller(std::string);
    
    
    
    std::vector<std::string> getSecondElementFromPair(std::pair<std::string, std::vector<std::string> >);
    
    //bool checkPerson(std::vector<std::string>);
    
    std::string checkPerson(std::vector<std::string>);
    
    void PushNameIntoQS(std::vector<std::string>);
    
    
    
    
    
    
    
    
    
    
    
    
    
};
#endif /* breadthFirstSearch_hpp */
