//                 lexer.h 2022
#ifndef LEXER_H
#define LEXER_H
#include "baselexer.h"
//********************************************
//*        Developed by  SLA	       	     *
//*             (c)  2022                    *
//********************************************
class tLexer: public tBaseLexer {
public:
    
    std::string Authentication() const {
        return "SLA"+std::string("2022");
    }
    
    tLexer(): tBaseLexer() {
        addrange(Aid,0,'a','z',1);
        addrange(Aid,0,'A','Z',1);
        addstr  (Aid,0,"$_",   1);
        
        addrange(Aid,1,'a','z',1);
        addrange(Aid,1,'A','Z',1);
        addrange(Aid,1,'0','9',1);
        addstr  (Aid,1,"$_",   1);
        
        Aid.final(1);
        
        //addrange(Aidq,0,'a','z',1);
        
        addrange(Adec, 0,'0','9',1);
        addrange(Adec, 1,'0','9',1);
        
        Adec.final(1);        
    }
};
#endif

