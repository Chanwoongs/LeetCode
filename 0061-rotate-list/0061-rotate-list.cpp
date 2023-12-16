class Solution {
public:
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev = nullptr,* curr = head, *forward = nullptr;
        while (curr != nullptr) 
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
    return prev;
    }
    int Length(ListNode* head)
    {
        int n = 0;
        while (head != nullptr)
        {
            head = head->next;
            n++;
        }
        return n;
    }
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(head == nullptr || head->next == nullptr)
        {
            return head;
        }   
        int n = Length(head);
        k = k % n;
        if(k == 0) return head;
        ListNode* newHead = reverse(head);

        ListNode* a1 = newHead,* a2 = newHead, *prev1 = newHead;
        while(k--)
        {
            prev1 = a1;
            a1 = a1->next;
        }
        prev1->next = nullptr;
        ListNode* fHead = reverse(a2);
        ListNode* jHead = reverse(a1);
        a1 = fHead;

        while(a1->next != nullptr)
        {
            a1 = a1->next;
        }
        a1->next = jHead;

        return fHead;
    }
};