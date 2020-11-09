#ifndef SLLIST_H
#define SLLIST_H

template<typename T> 
struct SLListElement //  идея за свързан списък с една връзка
{
	T data; // инф. част
	SLListElement* next; // указател към следващия елемент в паметта, връзка към елем., те се намират на разл. места в паметта
}; // ленейна стр-ра, на този ред не създава SLListElement, а казваме, че в него ще имаме указател към такъв елемент, 
//ще имаме един адрес, който адрес ще е на елемент от такъв тип, съответно този елем. може да бъде създ. по друго
//време на др. място и не се получава рекурсия

template<typename T>
class SLList;//дефинираме класа тук, за да може итератора да знае, че същ.

template<typename T>
class SLListIterator // абстракция на термина позиция, така че във всеки един момент да можем да получим една позиция от нашата стр-ра от данни
{                         // да можем да се предвижваме съответно напред и назад
	friend class SLList<T>;//необходимо е да работи с класа SLList, за да имаме достъп до представянето на елем., 
                          //казваме че ще имаме достъп до член-ф. и член-д. в рамките на класа, като го обявяваме за приятелски
	using LLE = SLListElement<T>;// изп. абривиетури
	using I = SLListIterator<T>;
	LLE* ptr; // указ. към SLListElem

public:
	using Type = T;
	SLListIterator(LLE* p = nullptr) : ptr(p) {} // конструктор

	I next() const // ф-я, чрез която се придвижваме към следващия елем. на стр-рата, искаме отново да ни връща итератор
	{
		if (!valid()) // проверка за валидност, дали не сме извън range-a  на стр-рата, или хвърляме exception или правим проверката
			return *this; //  и връщаме същата ст-ст без да правим промени

		return I(ptr->next);// използваме създ. конструктор, като по този начин си създ. итератор сочещ към следващата поз.
	}

	bool valid() const { return ptr != nullptr; }

	//функции, които ни позволяват да извличаме ст-та
	T const& getConst() const { return ptr->data; } // извлича контстантна референция и не ни дава възм. да я променяме
	T& get() const{ return ptr->data; } // извл. референция, позволявайки ни да я променяме

	 // синтактична захар
	// it <-> it.valid();
	operator bool() const { return valid(); }// предефиниране на булевия оператор

	// ++it
	I& operator++() {
		return (*this = next()); // освен че искаме да преместим итератора, искаме и да променим стойността на *this
	}

	// it++ отложено оценяване, първо взима стойността, която имаме в съотв.променлива и след това я променяме
	I operator++(int) {
		I save = *this; //създ. временна пром., която запазва тек. ст-ст
		++(*this); // променяве ст-та
		return save; // и връщаме предишната ст-ст, която сме запазили
	}

	// *it = 3;
	T& operator*() { return get(); } // типовете на функциите трябва да съвпадат

	bool operator==(I const& it) const { return ptr == it.ptr; }
	bool operator!=(I const& it) const { return !(*this == it); }

	I& operator+=(unsigned n) {
		for (unsigned i = 0; i < n; i++)
			++(*this);// придвижваме итератора с една позиция напред
		return *this;
	}
};

template <typename T>
class SLList {
	using LLE = SLListElement<T>;
	LLE* front, * back; // указатели към началото и края

	void erase();

public:

	using I = SLListIterator<T>;
	using Type = T;

	SLList() : front(nullptr), back(nullptr) {} // създава празен списък

	SLList(SLList const& ll);
	SLList& operator=(SLList const& ll);
	~SLList() { erase(); }

	bool empty() const { return front == nullptr; }

	bool insertBefore(I const& it, T const& x);
	bool insertAfter(I const& it, T const& x);

	bool deleteBefore(I const& it) { T tmp; return deleteBefore(it, tmp); }
	bool deleteAt(I const& it) { T tmp; return deleteAt(it, tmp); }
	bool deleteAfter(I const& it) { T tmp; return deleteAfter(it, tmp); }

	bool deleteBefore(I const& it, T& x);
	bool deleteAt(I const& it, T& x);
	bool deleteAfter(I const& it, T& x);

	// O(1) по време и памет
	bool insertFirst(T const& x) { return insertBefore(begin(), x); }
	bool insertLast(T const& x) { return insertAfter(end(), x); }

	// O(1) по време и памет
	bool deleteFirst(T& x) { return deleteAt(begin(), x); }
	// O(n) по време и O(1) по памет
	bool deleteLast(T& x) { return deleteAt(end(), x); }

	// O(1) по време и памет
	bool deleteFirst() { return deleteAt(begin()); }
	// O(n) по време и O(1) по памет
	bool deleteLast() { return deleteAt(end()); }

	T const& getAt(I const& it) const { return it.getConst(); }
	T& getAt(I const& it) { return it.get(); }

	I begin() const { return I(front); }
	I end()   const { return I(); } // Възможна реализация, която започва от последния елемент или от nullptr

	SLList<T>& operator+=(T const& x) { insertLast(x); return *this; }

	// залепва елементите на l в края на списъка
	void append(SLList const& l);

	// присвоява си елементите на l като ги залепва в края на списъка
	void appendAssign(SLList& l);
private:

	I findPrev(I const&);
};

// O(1) по време и памет
template <typename T>
bool SLList<T>::insertAfter(I const& it, T const& x) {
    if (empty()) {
        return insertFirst(x);
    }

    // it.ptr == nullptr <-> искаме да добавяме в края
    LLE* p = new LLE{ x, nullptr };

    if (!it || it.ptr == back) {
        // искаме да добавяме в края
        back->next = p;
        back = p;
    }
    else {
        // искаме да добавяме някъде по средата
        p->next = it.ptr->next;
        it.ptr->next = p;
    }
    return true;
}

// O(1) по време и по памет
template <typename T>
bool SLList<T>::deleteAfter(I const& it, T& x) {
    if (!it)
        // не можем да изтриваме след невалиден итератор
        return false;
    // it.valid()

    LLE* p = it.ptr->next;

    if (!p)
        // не можем да изтриваме след края
        return false;
    // p != nullptr

    it.ptr->next = p->next;
    x = p->data;

    if (back == p)
        // изтриваме последния елемент!
        back = it.ptr;

    delete p;
    return true;
}

// O(n) по време и O(1) по памет
template <typename T>
bool SLList<T>::insertBefore(I const& it, T const& x) {
    if (it == begin()) {
        // вмъкваме в началото: специален случай
        LLE* p = new LLE{ x, front };
        front = p;
        if (back == nullptr)
            // вмъкваме в празен списък
            back = p;
        return true;
    }
    return insertAfter(findPrev(it), x);
}

// O(n) по време и O(1) по памет
template <typename T>
SLListIterator<T> SLList<T>::findPrev(SLListIterator<T> const& it) {
    LLE* target;
    if (!it)
        // имаме предвид да търсим елемента преди последния
        target = back;
    else
        target = it.ptr;
    I result = begin();
    while (result && result.ptr->next != target)
        ++result;
    // result.ptr->next == target
    return result;
}

// O(n) по време и O(1) по памет
template <typename T>
bool SLList<T>::deleteAt(I const& it, T& x) {
    if (!empty() && it == begin()) {
        x = front->data;
        LLE* p = front;
        front = front->next;
        if (back == p)
            // изтриваме последния елемент от списъка
            back = nullptr;
        delete p;
        return true;
    }

    return deleteAfter(findPrev(it), x);
}

// O(n) по време и O(1) по памет
template <typename T>
bool SLList<T>::deleteBefore(I const& it, T& x) {
    if (it == begin())
        return false;
    return deleteAt(findPrev(it), x);
}

template <typename T>
SLList<T>::SLList(SLList const& l) : front(nullptr), back(nullptr) {
    append(l);
}

template <typename T>
SLList<T>& SLList<T>::operator=(SLList const& l) {
    if (this != &l) {
        erase();
        append(l);
    }
    return *this;
}

template <typename T>
void SLList<T>::append(SLList const& l) {
    for (T const& x : l)
        insertLast(x);
}

template <typename T>
void SLList<T>::erase() {
    while (!empty())
        deleteFirst();
}

template <typename T>
void SLList<T>::appendAssign(SLList& l) {
    if (back != nullptr)
        back->next = l.front;
    else
        front = l.front;

    if (l.back != nullptr)
        back = l.back;

    l.front = l.back = nullptr;
}
#endif // !SLLIST_H
