struct MyList
{
    int val;
    MyList* next;
    MyList(int x) : val(x), next(nullptr) {}
};

class MyLinkedList
{
private:
    MyList* _head;
    MyList* _tail;
    int len;

    MyList* createNode( int val )
    {
        MyList* temp = new MyList(val);
        return temp;
    }

public:
        MyLinkedList() : _head(nullptr),
                        _tail(nullptr),
                        len(0)
    {    
    }

    ~MyLinkedList()
    {
        MyList* current = _head;
        while (current) 
        {
            MyList* temp = current;
            current = current->next;
            delete temp;
        }
    }

    int get(int index)
    {
        if( index < 0 || index >= len)
            return -1;

        MyList* t = _head;
        int idx = 0;
        while(t && idx < index)
        {
            t = t->next;
            ++idx;
        }

        return t ? t->val : -1;
    }
    
    void addAtHead(int val)
    {
        MyList* t = createNode(val);
        if( !_head && !_tail )
        {
            _head = t;
            _tail = t;
        }
        else
        {
            t->next = _head;
            _head = t;
        }
        len += 1;
    }
    
    void addAtTail(int val)
    {
        MyList* t = createNode(val);
        if (!_head && !_tail)
        {
            _head = t;
            _tail = t;
        } 
        else 
        {
            _tail->next = t;
            _tail = t;
        }
        len += 1;
    }
    
    void addAtIndex(int index, int val)
    {
        if( index < 0 || index > len)
            return;

        MyList* t = createNode(val);
        if(index == 0)
        {
            // update the head node.
            addAtHead(val);
        }
        else if( index == len)
        {
            addAtTail(val);
        }
        else
        {
            MyList* temp = _head;
            int idx = 0;

            while( temp && idx < index-1 )
            {
                temp = temp->next;
                ++idx;
            }
            if(temp)
            {
                t->next = temp->next;
                temp->next = t;
            }
            len++;
        }
    }
    
    void deleteAtIndex(int index)
    {
        if( index < 0 || index >= len)
            return;

        if(index == 0)
        {
            // head node will be deleted;
            MyList* t = _head;
            _head = _head->next;

            if(!_head)
                _tail = nullptr;
            delete t;
        }
        else
        {
            MyList* temp = _head;
            MyList* prev = nullptr;
            for (int i = 0; i < index; ++i)
            {
                prev = temp;
                temp = temp->next;
            }
            
            if(prev && temp)
            {
                prev->next = temp->next;
                if(!prev->next)
                    _tail = prev;
            }
        }
        len -= 1;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */