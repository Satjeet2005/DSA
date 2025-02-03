    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* left = headA;
        ListNode* right = headB;
        int lengthA = 0,lengthB = 0,count = -1;

        while(left!=NULL){
            left = left->next;
            lengthA++;
        }

        while(right!=NULL){
            right = right-> next;
            lengthB++;
        }

        left = headA;
        right = headB;

        if(lengthA != lengthB){
            if(lengthA > lengthB){
                count = lengthA - lengthB;
                for(int i=0;i<count;i++){
                    left = left->next;
                }
            }

            else{
                count = lengthB - lengthA;
                for(int i=0;i<count;i++){
                    right = right->next;
                }
            }
        }

        while(left != NULL && right!=NULL){
            if(left == right){
                return left;
            }

            left = left->next;
            right = right->next;
        }

        return NULL;
        
    }
