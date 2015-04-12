#pragma once

template <typename T>
class Set
{
public:
    Set();
    ~Set();

    void add(T element);
    void remove(const T &element);
    bool exists(const T &element);
    int getSize() const;

    Set<T>* intersectSets(Set<T> *anotherSet);
    Set<T>* uniteSets(Set<T> *anotherSet);

private:
    class SetElement
    {
    public:
        SetElement();
        SetElement(SetElement *newNext, T newValue);
        SetElement *next;
        T value;
    };

    SetElement *head;
    int size;
};

template <typename T>
Set<T>::SetElement::SetElement() : next(nullptr)
{}

template <typename T>
Set<T>::SetElement::SetElement(Set<T>::SetElement *newNext, T newValue) : next(newNext), value(newValue)
{}

template <typename T>
Set<T>::Set() : head(new SetElement), size(0)
{}

template <typename T>
Set<T>::~Set()
{
    SetElement *current = head;
    while (current != nullptr)
    {
        SetElement *toDelete = current;
        current = current->next;
        delete toDelete;
    }
}

template <typename T>
void Set<T>::add(T element)
{
    if (!exists(element))
        head->next = new SetElement(head->next, element);
    size++;
}

template <typename T>
void Set<T>::remove(const T &element)
{
    SetElement *previous = head;
    SetElement *current = head->next;
    while (current != nullptr)
    {
        if (current->value == element)
        {
            previous->next = current->next;
            delete current;
            size--;
            break;
        }
        previous = current;
        current = current->next;
    }
}

template <typename T>
bool Set<T>::exists(const T &element)
{
    SetElement *current = head->next;
    while (current != nullptr)
    {
        if (current->value == element)
            return true;
        current = current->next;
    }
    return false;
}

template <typename T>
int Set<T>::getSize() const
{
    return size;
}

template <typename T>
Set<T> *Set<T>::intersectSets(Set<T> *anotherSet)
{
    Set<T> *intersection = new Set<T>;
    SetElement *current = head->next;
    while (current != nullptr)
    {
        if (anotherSet->exists(current->value))
            intersection->add(current->value);
        current = current->next;
    }
    return intersection;
}

template <typename T>
Set<T> *Set<T>::uniteSets(Set<T> *anotherSet)
{
    Set<T> *packing = new Set<T>;
    SetElement *current = head->next;
    while (current != nullptr)
    {
        packing->add(current->value);
        current = current->next;
    }

    current = anotherSet->head;
    while (current != nullptr)
    {
        packing->add(current->value);
        current = current->next;
    }
    return packing;
}
