//
// Created by 김혁진 on 14/10/2019.
//

#include "shared_mut.h"
#include "unique_immut.h"

namespace ptr {
shared_mut::shared_mut() {
    this->_mgr = new mgr();
}

shared_mut::shared_mut(Object* _obj) {
    this->_mgr = new mgr(_obj);
}

shared_mut::~shared_mut() {
    release();
}

Object* shared_mut::operator->() {
    return this->_mgr->ptr;
}

void shared_mut::increase(){
	this->_mgr->count ++;
}

Object* shared_mut::get() const{
	return this->_mgr->ptr;
}
void shared_mut::release(){
	this->_mgr->count --;
	if(this->_mgr->count==0){
		delete(_mgr->ptr);
		this->_mgr->ptr = nullptr;
	}
}
int shared_mut::count(){
	return this->_mgr->count;
}
shared_mut shared_mut::operator+(const shared_mut &shared){
	int newVal = this->_mgr->ptr->get() + shared._mgr->ptr->get();
	shared_mut r(new Object(newVal));
	return r;
}
shared_mut shared_mut::operator-(const shared_mut &shared){
	int newVal = this->_mgr->ptr->get() - shared._mgr->ptr->get();
	shared_mut r(new Object(newVal));
	return r;
}
shared_mut shared_mut::operator*(const shared_mut &shared){
	int newVal = this->_mgr->ptr->get() - shared._mgr->ptr->get();
	shared_mut r(new Object(newVal));
	return r;
}
shared_mut shared_mut::operator/(const shared_mut &shared){
	int newVal = this->_mgr->ptr->get() / shared._mgr->ptr->get();
	shared_mut r(new Object(newVal));
	return r;
}
shared_mut shared_mut::operator=(const shared_mut &r){
	release();
	this->_mgr = r._mgr;
	r._mgr->count++;
	increase();
	return *this;
}

} // end of namespace ptr
