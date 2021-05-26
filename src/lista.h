#ifndef list_h
#define list_h

template<typename type> 
class link {
public:
	link *prev, *next;
	type data;
	
};

template<typename type> 
class list {
	link<type> *head, *tail;
	int size;
public:
	 list();
	 ~list();
	 void Add_end(const type &dane);
	 void Add_start(const type &dane);
	 void Delete_end();
	 void Delete_start();
	 type * Show_element(int);
	 void Change_element(int, const type &dane);
	 link<type> * Find_data(const type dane);
	 bool Find_data_del(const type dane);
	 bool add_sort(const type dane);
	 void clear();
	 void List_elements(void (*write)(type ob));
	

};


template<typename type> list<type>::list() {
	head = nullptr;
	tail = nullptr;
	size = 0;
}

template<typename type>
list<type>::~list(){
	
}

template<typename type>
void list<type>::Add_end(const type &dane) {
	link<type> *ptr;
	ptr = new link<type>(); 
	ptr->data = dane;  
	ptr->next = nullptr; 
	ptr->prev = tail; 
	if (ptr->prev==nullptr) {
		head = ptr; 
		tail = ptr; 
	}
	else {
		tail->next = ptr;
		tail = ptr;
	}
	size++;
	
}

template <typename type>
void list<type>::Add_start(const type &dane) {
	link<type> *ptr;
	ptr = new link<type>();
	ptr->data = dane;
	ptr->prev = nullptr;
	ptr->next = head;
	if (ptr->next==nullptr) {
		head = ptr;
		tail = ptr;
	}
	else {
		head->prev = ptr;
		head = ptr;
	}
	size++;
}
template<typename type>
void list<type>::Delete_end(){
		if (size > 1) {
			link<type> *litem;
			litem = tail->prev;
			delete tail;
			tail = litem;
			tail->next = nullptr;
			size--;
		}
		else if (size == 1) {
			delete tail;
			tail = nullptr;
			head = nullptr;
			size--;
		}
		else {
			std::cout << ("Brak elementow listy! ")<< std::endl;
		}
}

template<typename type>
void list<type>::Delete_start() {
	if (size > 1) {
		link<type> *litem;
		litem = head->next;
		delete head;
		head = litem;
		head->prev = nullptr;
		size--;
	}
	else if (size == 1) {
		delete head;
		tail = nullptr;
		head = nullptr;
		size--;
	}
	else {
		std::cout << "Brak elementow listy! " << std::endl;
	}
}
	

template<typename type>
 type * list<type>::Show_element(int i){
		if (i < 0 || i > size - 1) {
			std::cout << "Poza zasiegiem listy! " << std::endl;
			return nullptr;
		}
		else{
		link<type> *ptr;
		ptr = head;
		while (i != 0) {
			ptr = ptr->next;
			i--;
		}
		return &ptr->data;
	}
}

template<typename type>
void list<type>::Change_element(int i, const type & dane){
	if (i < 0 || i > size - 1) {
		std::cout << "Poza zasiegiem listy! " << std::endl;
	}
	else {
		link<type> *ptr;
		ptr = head;
		while (i != 0) {
			ptr = ptr->next;
			i--;
		}
		ptr->data = dane;
	}

}
template<typename type>
link<type> * list<type>::Find_data(const type dane){
	link<type> *ptr;
	ptr = head;
	int i = size;
	while (i!=0) {
		if (ptr->data == dane) {
			return ptr;
		}
		ptr = ptr->next;
		i--;
	}
	return nullptr;
	}

template<typename type>
bool list<type>::Find_data_del(const type dane)
{
	link<type> *ptr;
	ptr = head;
	int i = size;
	while (i!=0) {
		if (ptr->data == dane) {
			if (size == 1) {
				delete ptr;
				tail = nullptr;
				size--;
				return true;
			}
			else {
				if (ptr == head) {
					head = ptr->next;
					ptr->next->prev = nullptr;
					delete ptr;
					size--;
					return true;
				}
				else if (ptr == tail) {
					tail = ptr->prev;
					ptr->prev->next = nullptr;
					delete ptr;
					size--;
					return true;
				}
				else {
					ptr->next->prev = ptr->prev;
					ptr->prev->next = ptr->next;
					delete ptr;
					size--;
					return true;
				}
			}
		}
		ptr = ptr->next;
		i--;
	}
	return false;
}

template<typename type>
bool list<type>::add_sort(const type dane){
	if (size == 0) {
		Add_start(dane); //ok
		return true;
	}
	else {
		link<type> *ptr;
		link<type> *new_element = new link<type>();
		new_element->data = dane;
		ptr = head;
		int i = size;
		while (i != 0) {
			if (ptr->data < dane) {
				if (size == 1) {
					Add_start(dane); //ok
					delete new_element;
					return true;
				}
				else {
					if (ptr == head) {
						Add_start(dane);//ok
						delete new_element;
						return true;
					}
					else if (ptr == tail) {
						tail->prev->next = new_element; //ok
						new_element->prev = tail->prev;
						tail->prev = new_element;
						new_element->next = tail;
						size++;
						return true;
					}
					else {
						ptr->prev->next = new_element;
						new_element->prev = ptr->prev;
						ptr->prev = new_element;
						new_element->next = ptr;
						
						size++;
						return true;
					}
				}
			}
			else if (ptr == tail) {
				Add_end(dane); //ok
				delete new_element;
				return true;
			}
			else {
				ptr = ptr->next;
				i--;
			}
		}
	}
}


	

template<typename type>
 void list<type>::clear(){
	 link<type> *ptr;
	while (size!=0)
	{
		if (size == 1) {
			ptr = head;
			delete ptr;
			size--;
		}
		else {
			ptr = head;
			head = ptr->next;
			delete ptr;
			size--;
		}
	}
	tail = nullptr;
	head = nullptr;
}

 

 template<typename type>
 void list<type>::List_elements(void (*write)(type ob)){
	 link<type> *ptr=head;
	 int i = 0;
	 while (i != size) {
		 std::cout << "element: " << i << std::endl;
		 std::cout << "adres: " << ptr << std::endl;
		 write(ptr->data);
		 i++;
		 ptr = ptr->next;
	 }
 }


	
#endif

