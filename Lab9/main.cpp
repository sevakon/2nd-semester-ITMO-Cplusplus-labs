//
//  main.cpp
//  lab2_9
//
//  Created by Владимир Коняхин on 13/05/2019.
//  Copyright © 2019 Vsevolod Konyakhin. All rights reserved.
//

#include <iostream>
#include <string>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>

float firstRatio = 0;
float secondRatio = 0;
float ratio;

static void getCurrencies(xmlNode * aNode, const char * cur1, const char * cur2) {
    xmlNode *curNode = NULL;

    
    for (curNode = aNode; curNode; curNode = curNode->next) {
        char * currentCurrency;
        float currentRate;
        if (curNode->type == XML_ELEMENT_NODE) {
            if (xmlStrlen(curNode->name) == 8) {
                currentCurrency = (char*)curNode->children->content;
            } else if (xmlStrlen(curNode->name) == 5) {
                currentRate = std::stof(std::string((char*)curNode->children->content));
                std::cout << currentCurrency << " " << currentRate << std::endl;
                
                if (strcmp(currentCurrency, cur1)) {
                    firstRatio = currentRate;
//                    std::cout << firstRatio << std::endl;
                } else if (strcmp(currentCurrency, cur2)) {
                    secondRatio = currentRate;
//                    std::cout << secondRatio << std::endl;
                }
            }

        }
        

        
        getCurrencies(curNode->children, cur1, cur2);
    }
    

}


int main(int argc, const char * argv[]) {
    xmlDoc *doc = NULL;
    xmlNode *rootElement = NULL;

    doc = xmlReadFile("/Users/vkonyakhin/Desktop/daily_eng.xml", NULL, 0);
    
    if (doc == NULL) {
        std::cout << "could not parse file "<< std::endl;
        return 1;
    }
    
    rootElement = xmlDocGetRootElement(doc);
    getCurrencies(rootElement, argv[1], argv[2]);
    
    ratio = firstRatio/secondRatio;
    std::cout << "from " << argv[1] << " to " << argv[2] << ": "<< ratio << std::endl;

    //free the document
    xmlFreeDoc(doc);
    xmlCleanupParser();
    
    return 0;
}
