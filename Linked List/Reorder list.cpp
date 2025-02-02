    ListNode* splitLL(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while(fast!=NULL && fast->next!=NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = NULL;
        return slow;
    }

    ListNode* reverseLL(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* currNext = curr->next;

        while(currNext != NULL){
            currNext = curr->next;
            curr->next = prev;
            prev = curr;
            curr = currNext;
        }

        return prev;
    }

    void reorderList(ListNode* left) {
        if(left->next == NULL || left->next->next == NULL){
            return;
        }

        ListNode* right = splitLL(left);
        right = reverseLL(right);

        if(left == right){
            return;
        }

        while(true){
            ListNode* nextLeft = left->next;
            left->next = right;
            ListNode* nextRight = right->next;
            right->next = nextLeft;
            if(nextLeft == NULL){
                while(nextRight!=NULL){
                    ListNode* temp = right;
                    temp->next = nextRight;
                    temp = nextRight;
                    nextRight = nextRight -> next;
                }
                return;
            }
            left = nextLeft;
            right = nextRight;
        } 
