#include "C.h"

// ������ǿ���ָ��ľ���Ӧ�á�ֻ��Ҫ������ָ�룬һ��ÿ����һ������slowָ���һ��ÿ���������Ŀ�fastָ��
// ����������л��Ļ�������ָ�����տ϶���������ʵ����̫������!

bool hasCycle(ListNode* head)
{
	auto slow = head; 
	auto fast = head; // ������ָ��head�����ǲ������ʲ�һ����
	
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
