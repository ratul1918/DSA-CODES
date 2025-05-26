void insertFirst(int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void insertLast(int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

void insertAt(int data, int position) {
    if (position <= 0) {
        cout << "Invalid position!" << endl;
        return;
    }

    Node* newNode = new Node(data);
    if (position == 1) {
        insertFirst(data);
        return;
    }

    Node* current = head;
    for (int i = 1; i < position - 1 && current != nullptr; i++) {
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Position out of bounds!" << endl;
        return;
    }

    newNode->next = current->next;
    if (current->next != nullptr) {
        current->next->prev = newNode;
    }
    current->next = newNode;
    newNode->prev = current;
}

void deleteFirst() {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;
    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr;
    }
    delete temp;
}

void deleteLast() {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* current = head;
    if (current->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    while (current->next != nullptr) {
        current = current->next;
    }

    current->prev->next = nullptr;
    delete current;
}

void deleteItem(int item) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* current = head;
    while (current != nullptr && current->data != item) {
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Item not found!" << endl;
        return;
    }

    if (current->prev != nullptr) {
        current->prev->next = current->next;
    } else {
        head = current->next;
    }

    if (current->next != nullptr) {
        current->next->prev = current->prev;
    }

    delete current;
}