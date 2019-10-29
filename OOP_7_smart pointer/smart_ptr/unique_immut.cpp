//
// Created by 김혁진 on 14/10/2019.
//

#include "unique_immut.h"

namespace ptr {
unique_immut::unique_immut() {
    _mgr = new mgr();
}

unique_immut::unique_immut(Object *obj) {
    _mgr = new mgr(obj);
}

unique_immut::unique_immut(const unique_immut &immut) {
    if (immut._mgr) {
        int val = immut._mgr->ptr->get();
        _mgr = new mgr(val);
    }
}

unique_immut::~unique_immut() {
    release();
}

Object* unique_immut::get() const{
	return _mgr->ptr;
}

void unique_immut::release(){
	if(_mgr->ptr!=nullptr){
		delete(_mgr->ptr);
		_mgr->ptr = nullptr;
	}
}

unique_immut unique_immut::operator+(unique_immut &unique){
	int newVal = _mgr->ptr->get() + unique._mgr->ptr->get();
	release();
	unique.release();
	unique_immut r(new Object(newVal));
	return r;
}

unique_immut unique_immut::operator-(unique_immut &unique){
	int newVal = _mgr->ptr->get() - unique._mgr->ptr->get();
	release();
	unique.release();
	unique_immut r(new Object(newVal));
	return r;
}

unique_immut unique_immut::operator*(unique_immut &unique){
	int newVal = _mgr->ptr->get() * unique._mgr->ptr->get();
	release();
	unique.release();
	unique_immut r(new Object(newVal));
	return r;
}

unique_immut unique_immut::operator/(unique_immut &unique){
	int newVal = _mgr->ptr->get() / unique._mgr->ptr->get();
	release();
	unique.release();
	unique_immut r(new Object(newVal));
	return r;
}

Object* unique_immut::operator->(){
	return _mgr->ptr;
}

/*unique_immut unique_immut::operator=(unique_immut &r){
	if(_mgr==r._mgr){
		return *this;
	}
	else{
		release();
		_mgr = r._mgr;
		r.release();
		return *this;
	}
}*/	
} // end of namespace ptr
