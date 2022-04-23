#pragma once
#include <string>
#include <set>

using std::string;
using std::set;

class Folder;

class Message
{
	friend void swap(Message& lhs, Message& rhs);
	friend class Folder;
public:
	explicit Message(const std::string& str = "") : contents(str) {
	}
	Message(const Message&);
	Message(Message&&);
	Message& operator=(const Message&);
	Message& operator=(Message&&);
	~Message();
	void save(Folder&);
	void remove(Folder&);  
	void addFldr(Folder*);
	void debug_print();
private:
	string contents;
	set<Folder*> folders;
	void add_to_Folders(const Message&);
	void remove_from_Folders();
	void remFldr(Folder* f) { folders.erase(f); }
	void move_Folders(Message*);
};

class Folder {
	friend void swap(Message& lhs, Message& rhs);
	friend class Message;
public:
	Folder() = default;
	Folder(const Folder& f) :msgs(f.msgs) {
		add_to_Messsage(f);
	}
	Folder& operator=(const Folder& f) {
		remove_from_Msgs();
		msgs = f.msgs;
		add_to_Messsage(f);
		return *this;
	}
	void save(Message&);   
	void remove(Message&);
	void debug_print();
	~Folder() {
		remove_from_Msgs();
	}
private:
	set<Message*> msgs;
	void addMsg(Message*);
	void remMsg(Message*);
	void add_to_Messsage(const Folder& f);
	void remove_from_Msgs();

};

