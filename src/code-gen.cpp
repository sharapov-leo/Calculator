/* $gpred22*/
#include "code-gen.h"
#include "longArithmetic.h"
using namespace std;
bool okc = true;
std::string tCG::decor(const std::string& id) {
	static const char* cpp_reserved[] = {
	 "try",
	 //????????????????????????
		"main"
	};
	static const size_t n =
		sizeof(cpp_reserved) / sizeof(char*);
	for (size_t i = 0; i < n; ++i)
		if (id == cpp_reserved[i])
			return "__" +
			lex.Authentication() +
			"__" + id;
	// заменить '-','!','?'
	std::string tmp;
	for (size_t i = 0; i < id.size(); ++i) {
		switch (id[i]) {
		case '?': tmp += "_Q"; break;
		case '!': tmp += "_E"; break;
		case '-': tmp += "__"; break;
		default: tmp += id[i];
		}
	}
	return tmp;
}
int tCG::p01(){ //    S -> E
	if (!okc)
		S1->obj = "Error";
	okc = true;
	return 0;}
int tCG::p02(){ //    E -> T1
	return 0;}
int tCG::p03(){ //    T1 -> T2
	return 0;}
int tCG::p04(){ //    T1 -> T1 < T2
	if(okc) {
		std::string first = S1->obj;
		std::string second = S3->obj;
		longNumber a, b;
		first >> a;
		second >> b;
		S1->obj = ((a.cmp(b) < 0) ? "#t" : "#f");
	}
	return 0;}
int tCG::p05(){ //    T1 -> T1 > T2
	if(okc) {
		std::string first = S1->obj;
		std::string second = S3->obj;
		longNumber a, b;
		first >> a;
		second >> b;
		S1->obj = ((a.cmp(b) > 0) ? "#t" : "#f");
	}
	return 0;}
int tCG::p06(){ //    T1 -> T1 == T2
	if(okc) {
		std::string first = S1->obj;
		std::string second = S3->obj;
		longNumber a, b;
		first >> a;
		second >> b;
		S1->obj = (a == b ? "#t" : "#f");
	}
	return 0;}
int tCG::p07(){ //     T2 -> T3
	return 0;}
int tCG::p08(){ //     T2 -> T2 + T3
	if(okc) {
		std::string augend = S1->obj;
		std::string addend = S3->obj;
		longNumber a, b;
		augend >> a;
		addend >> b;
		S1->obj << (a + b);
	}
	return 0;}
int tCG::p09(){ //     T2 -> T2 - T3
	if(okc) {
		std::string minuend = S1->obj;
		std::string subtrahend = S3->obj;
		longNumber a, b;
		minuend >> a;
		subtrahend >> b;
		std::cout <<a.cmp(b) << std::endl;
		if (a.cmp(b) < 0) {
			//S1->obj = "Error: subtraction result is less than zero\n";
			okc=false;
		}
		else 
			S1->obj << (a - b);
	}
	return 0;}
int tCG::p10(){ //     T3 -> T4
	return 0;}
int tCG::p11(){ //     T3 -> T3 * T4
	if(okc) {
		std::string multiplicand = S1->obj;
		std::string multiplier = S3->obj;
		longNumber a, b;
		multiplicand >> a;
		multiplier >> b;
		a = a * b;
		S1->obj << a;
	}
	return 0;}
int tCG::p12(){ //     T3 -> T3 / T4
	if(okc) {
		std::string dividend = S1->obj;
		std::string divisor = S3->obj;
		longNumber a, b;
		dividend >> a;
		divisor >> b;
		if (b == 0){
			okc=false;
			//S1->obj = "Error: divide-by-zero\n"; // ok = false;
		}
		else {
			a = a/b;
			S1->obj << a;
		}
	}
	return 0;}
int tCG::p13(){ //     T4 -> $dec
	S1->obj = decor(S1->name);
	return 0;}
int tCG::p14(){ //     T4 -> ( E )
	S1->obj = S2->obj;
	return 0;}
//_____________________
int tCG::p15(){return 0;} int tCG::p16(){return 0;} 
int tCG::p17(){return 0;} int tCG::p18(){return 0;} 
int tCG::p19(){return 0;} int tCG::p20(){return 0;} 
int tCG::p21(){return 0;} int tCG::p22(){return 0;} 
int tCG::p23(){return 0;} int tCG::p24(){return 0;} 
int tCG::p25(){return 0;} int tCG::p26(){return 0;} 
int tCG::p27(){return 0;} int tCG::p28(){return 0;} 
int tCG::p29(){return 0;} int tCG::p30(){return 0;} 
int tCG::p31(){return 0;} int tCG::p32(){return 0;} 
int tCG::p33(){return 0;} int tCG::p34(){return 0;} 
int tCG::p35(){return 0;} int tCG::p36(){return 0;} 
int tCG::p37(){return 0;} int tCG::p38(){return 0;} 
int tCG::p39(){return 0;} int tCG::p40(){return 0;} 
int tCG::p41(){return 0;} int tCG::p42(){return 0;} 
int tCG::p43(){return 0;} int tCG::p44(){return 0;} 
int tCG::p45(){return 0;} int tCG::p46(){return 0;} 
int tCG::p47(){return 0;} int tCG::p48(){return 0;} 
int tCG::p49(){return 0;} int tCG::p50(){return 0;} 
int tCG::p51(){return 0;} int tCG::p52(){return 0;} 
int tCG::p53(){return 0;} int tCG::p54(){return 0;} 
int tCG::p55(){return 0;} int tCG::p56(){return 0;} 
int tCG::p57(){return 0;} int tCG::p58(){return 0;} 
int tCG::p59(){return 0;} int tCG::p60(){return 0;} 
int tCG::p61(){return 0;} int tCG::p62(){return 0;} 
int tCG::p63(){return 0;} int tCG::p64(){return 0;} 
int tCG::p65(){return 0;} int tCG::p66(){return 0;} 
int tCG::p67(){return 0;} int tCG::p68(){return 0;} 
int tCG::p69(){return 0;} int tCG::p70(){return 0;} 
int tCG::p71(){return 0;} int tCG::p72(){return 0;} 
int tCG::p73(){return 0;} int tCG::p74(){return 0;} 
int tCG::p75(){return 0;} int tCG::p76(){return 0;} 
int tCG::p77(){return 0;} int tCG::p78(){return 0;} 
int tCG::p79(){return 0;} int tCG::p80(){return 0;} 
int tCG::p81(){return 0;} int tCG::p82(){return 0;} 
int tCG::p83(){return 0;} int tCG::p84(){return 0;} 
int tCG::p85(){return 0;} int tCG::p86(){return 0;} 
int tCG::p87(){return 0;} int tCG::p88(){return 0;} 
int tCG::p89(){return 0;} int tCG::p90(){return 0;} 
int tCG::p91(){return 0;} int tCG::p92(){return 0;} 
int tCG::p93(){return 0;} int tCG::p94(){return 0;} 
int tCG::p95(){return 0;} int tCG::p96(){return 0;} 
int tCG::p97(){return 0;} int tCG::p98(){return 0;} 
int tCG::p99(){return 0;} int tCG::p100(){return 0;} 
int tCG::p101(){return 0;} int tCG::p102(){return 0;} 
int tCG::p103(){return 0;} int tCG::p104(){return 0;} 
int tCG::p105(){return 0;} int tCG::p106(){return 0;} 
int tCG::p107(){return 0;} int tCG::p108(){return 0;} 
int tCG::p109(){return 0;} int tCG::p110(){return 0;} 


