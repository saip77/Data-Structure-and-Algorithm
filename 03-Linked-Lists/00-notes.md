
# 🧩 Linked List

## 🔹 1. Node Structure

```cpp
struct Node {
    int data;
    Node* next;
};
```

👉 `data` = value
👉 `next` = pointer to next node

---

## 🔹 2. Key Concept

> Linked list = nodes connected by pointers

```text
[10] → [20] → [30] → NULL
```

---

# 🔹 3. Traversal

```cpp
void printList(Node* head){
    while(head != nullptr){
        cout << head->data << " ";
        head = head->next;
    }
}
```

🧠 Move using: `head = head->next`

---

# 🔹 4. Insertion

## ✅ At Beginning (O(1))

```cpp
void insertAtStart(Node*& head, int val){
    Node* newNode = new Node{val, head};
    head = newNode;
}
```

👉 New node points to old head

---

## ✅ At End (O(n))

```cpp
void insertAtEnd(Node*& head, int val){
    Node* newNode = new Node{val, nullptr};

    if(head == nullptr){
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }

    temp->next = newNode;
}
```

---

# 🔹 5. Deletion

## ✅ Delete at Start

```cpp
void deleteAtStart(Node*& head){
    if(head == nullptr) return;

    Node* temp = head;
    head = head->next;
    delete temp;
}
```

---

## ✅ Delete at End

```cpp
void deleteAtEnd(Node*& head){
    if(head == nullptr) return;

    if(head->next == nullptr){
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;
    while(temp->next->next != nullptr){
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;
}
```

---

## ✅ Delete by Value

```cpp
void deleteValue(Node*& head, int val){
    if(head == nullptr) return;

    if(head->data == val){
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;
    while(temp->next != nullptr && temp->next->data != val){
        temp = temp->next;
    }

    if(temp->next == nullptr) return;

    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}
```

---

