#include "Message.h"

#include <iostream>

using std::cerr;
using std::endl;

void Message::save(Folder& f)
{
	folders.insert(&f); // add the given Folder to our list of Folders
	f.addMsg(this);     // add this Message to f's set of Messages
}

void Message::remove(Folder& f)
{
	folders.erase(&f); // take the given Folder out of our list of Folders
	f.remMsg(this);    // remove this Message to f's set of Messages
}
 
void Message::addFldr(Folder* f) {
	folders.insert(f);
}

void Message::add_to_Folders(const Message& m) {
	for (auto f : m.folders) {
		f->addMsg(this);
	}
}

void Message::remove_from_Folders() {
	for (auto f : folders) {
		f->remMsg(this);
	}
}

Message::Message(const Message& m) :
	contents(m.contents), folders(m.folders) {
	add_to_Folders(m);
}

Message::Message(Message&& m): contents(std::move(m.contents)) {
	move_Folders(&m);
}

Message& Message::operator=(const Message& rhs) {
	remove_from_Folders();
	contents = rhs.contents;
	folders = rhs.folders;
	add_to_Folders(rhs);
	return *this;
}

Message& Message::operator=(Message&& rhs) {
	if (this != &rhs)
	{
		remove_from_Folders();
		contents = std::move(rhs.contents); 
		move_Folders(&rhs);
	}
	return *this;
}

void Message::move_Folders(Message* m) {
	folders = std::move(m->folders);
	for (auto f : folders) {
		f->remMsg(m);
		f->addMsg(this);
	}
	m->folders.clear();
}

Message::~Message() {
	remove_from_Folders();
} 

void Folder::addMsg(Message* m) {
	msgs.insert(m);
}

void Folder::remMsg(Message* m) {
	msgs.erase(m); 
}

void Folder::add_to_Messsage(const Folder& f) {
	for (auto msg : f.msgs) {
		msg->addFldr(this);
	}
}
void Folder::remove_from_Msgs() {
	while (!msgs.empty()) {
		(*msgs.begin())->remove(*this);
	}
}

void swap(Message& lhs, Message& rhs) {
	using std::swap;
	for (auto f : lhs.folders) {
		f->remMsg(&lhs);
	}
	for (auto f : rhs.folders) {
		f->remMsg(&rhs);
	}
	swap(lhs.folders, rhs.folders);
	swap(lhs.contents, rhs.contents);
	for (auto f : lhs.folders) {
		f->addMsg(&lhs);
	}
	for (auto f : rhs.folders) {
		f->addMsg(&rhs);
	}
}

void Folder::debug_print()
{
	cerr << "Folder contains " << msgs.size() << " messages" << endl;
	int ctr = 1;
	for (auto m : msgs) {
		cerr << "Message " << ctr++ << ":\n\t" << m->contents << endl;
	}
}

void Folder::save(Message& m)
{
	// add m and add this folder to m's set of Folders
	msgs.insert(&m);
	m.addFldr(this);
}

void Folder::remove(Message& m)
{
	// erase m from msgs and remove this folder from m
	msgs.erase(&m);
	m.remFldr(this);
}

void Message::debug_print()
{
	cerr << "Message:\n\t" << contents << endl;
	cerr << "Appears in " << folders.size() << " Folders" << endl;
}

