#include "C.h"

// 这道题是快慢指针的经典应用。只需要设两个指针，一个每次走一步的慢slow指针和一个每次走两步的快fast指针
// 如果链表里有环的话，两个指针最终肯定会相遇。实在是太巧妙了!

bool hasCycle(ListNode* head)
{
	auto slow = head; 
	auto fast = head; // 两个都指向head，但是步数速率不一样！
	
	while (fast)
	{
		if (!fast->next)
			return false;
		
		fast = fast->next->next;
		slow = slow->next;
		
		if (fast == slow)
			return true;
	}
	return false;
}
