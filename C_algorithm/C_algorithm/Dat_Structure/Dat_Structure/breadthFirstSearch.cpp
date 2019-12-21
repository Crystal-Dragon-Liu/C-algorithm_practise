//
//  breadthFirstSearch.cpp
//  Dat_Structure
//
//  Created by  云子谣 on 2019/12/18.
//  Copyright © 2019  云子谣. All rights reserved.
//

#include "breadthFirstSearch.hpp"

using namespace std;


breadthFirstSearch::breadthFirstSearch()
{
    me  = {"me", {"alice", "bob", "claire"}};
    //一度关系
    bob = {"bob", {"anuj","peggy"}};
    claire = {"claire", {"thom","jonny"}};
    alice = {"alice", {"peggy"}};
    
    //二度关系
    anuj = {"anuj", {""}};
    peggy = {"anuj", {""}};
    thom = {"anuj", {""}};
    jonny = {"anuj", {""}};
    
    graph.insert(me);
    
    graph.insert(bob);
    graph.insert(claire);
    graph.insert(alice);
    
    graph.insert(anuj);
    graph.insert(peggy);
    graph.insert(thom);
    graph.insert(jonny);
    
    q.push(graph["me"]);
}

bool breadthFirstSearch::findSeller()
{
    while (q.size() != 0 )
    {
        
//        string curPeoples =
        auto curPeoples = q.front();
        q.pop();
        //PushNameIntoQS(curPeoples);
        
        for(auto i = curPeoples.begin();i != curPeoples.end(); i++)
        {
            cout << "current People is " << *i << endl;
            if(PersonIsSeller(*i))
            {
                 cout << "seller is " << *i << endl;
                 return true;
            }
            else
            {
                q.push(graph[*i]);
                
                
            }
            
            
        }
        
        //string curPeople = q_s.front();
        
        
//        while (q_s.size() != 0)
//        {
//            string curPeople = q_s.front();
//            q_s.pop();
//
//            if (PersonIsSeller(curPeople))
//            {
//                cout << curPeople << endl;
//                return true;
//            }
//            else
//            {
//                q.push(graph[curPeople]);
//
//            }
//        }
        
   
    }
    
//    while (q.size() != 0)
//    {
//        auto person = q.front();
//        q.pop();
//        if (checkPerson(person))
//        {
//            cout << "is the seller" << endl;
//        }
//        else
//        {
          //q.push();
//        }
//
//
//    }
//
    cout << "failed" << endl;
    return false;

}

bool breadthFirstSearch::PersonIsSeller(string person)
{
    cout << "for " << person << "the last is " << person[-1] << endl;
    cout << "for " << person << "the last is " << person[person.size()-1] << endl;

    return person[person.size()-1] == 'm';
    
}

vector<string> breadthFirstSearch::getSecondElementFromPair(pair<string, vector<string> > p)
{
    return p.second;
    
}

string  breadthFirstSearch::checkPerson(vector<string> person)
{
//
//   for (auto i = person.begin(); i != person.end(); i++)
//   {
//      if(PersonIsSeller(*i))
//        {
//            cout << *i << endl;
//            return *i;
//       }
//
//   }
//
    return "";
     
    
}

void breadthFirstSearch::PushNameIntoQS(vector<string> CurPeoples )
{
    for (auto i = CurPeoples.begin(); i != CurPeoples.end(); i++) {
        q_s.push(*i);
    }
}
