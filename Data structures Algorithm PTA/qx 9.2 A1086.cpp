// A1086. Tree Traversals Again

//----CODE-----

#include "C.h"

const int maxn = 50;

struct node 
{
	int data;
	node* lchild;
	node* rchild;
};

//---�������򡢺���---
int pre[maxn], in[maxn], post[maxn];

//---n��ʾ������---
int n;

//---��ǰ��������������������Ϊ[preL,preR]---
//---������������Ϊ[inL, inR]---
//---create�������ع������Ķ������ĸ�����ַ(Ҳ����root)---
node* create(int preL, int preR, int inL, int inR) 
{
	//---���������г���С�ڵ���0����ֱ�ӷ���---
	if (preL > preR) 
	{
		return NULL;
	}

	//---�½�һ���µĽ�㣬������ŵ�ǰ�������ĸ����---
	node* root = new node;

	//---�½���������(root->data)Ϊ������ֵ(pre[preL]���������������߽�)---
	root->data = pre[preL];

	int k;
	for (k = inL; k <= inR; k++) 
	{
		//---�������������ҵ�in[k] == pre[preL]�Ľ��---
		//---Ҳ������������������һ��λ��k��in[k]�洢�ľ��Ƕ������ĸ�����ֵ---
		if (in[k] == pre[preL])
		{
			break;
		}
	}

	//---numLeftΪ�������ĸ���---
	int numLeft = k - inL;

	//---�����ұ�create()�����������ĸ�����ַ---
	//---��ֵ��root����ָ��---
	root->lchild = create(preL + 1, preL + numLeft, inL, k - 1); // create()�����зֱ������������
																 // ����������Χ����������Χ

	//---�����ұ�create()�����������ĸ�����ַ---
	//---��ֵ��root����ָ��---
	root->rchild = create(preL + numLeft + 1, preR, k + 1, inR);

	//---���ظ�����ַ---
	return root;
}

//---������Ľ�����---
int num = 0;

//---�������---
void postorder(node* root) 
{
	if (root == NULL) 
	{
		return;
	}

	postorder(root->lchild);
	postorder(root->rchild);

	printf("%d", root->data);
	num++;

	if (num < n) 
		printf(" ");
}

int main() 
{
	//---n��ʾ������---
	scanf("%d", &n);

	//---str��������ʾpush��pop���������ʵ�---
	char str[5];

	//---����һ��int���͵�ջst---
	stack<int> st;
	
	//---x��ʾ��ջԪ��---
	int x;

	//---preIndex��ʾ��������λ�ã�inIndex��ʾ��������λ��---
	int preIndex = 0, inIndex = 0;

	//---2n��ʾ��ջ��ջ��2n��---
	for (int i = 0; i < 2 * n; i++) 
	{
		//---����Push����Pop---
		scanf("%s", str);

		//---��ջ---
		if (strcmp(str, "Push") == 0) 
		{
			scanf("%d", &x);

			//---���������pre[preIndex] = x---
			pre[preIndex++] = x;

			//---��ջst��pushԪ��x---
			st.push(x);
		}
		else 
		{
			//---���������in[inIndex] = st.top() ����ջ��Ԫ��---
			in[inIndex++] = st.top();

			//---ջ����pop---
			st.pop();
		}
	}

	//---���������������������ķ�Χ[0, n-1]����������---
	node* root = create(0, n - 1, 0, n - 1);  // main()�����е�create()�ķ�Χһֱ��[0,n-1]
											  // ��create()�л�ݹ�ʹ��create()������ķ�Χ����廯

	//---�������---
	postorder(root);

	return 0;
}


//----Summary----
// postorder��create���ǵݹ飬Ҳ����˵����������ͨ����������õ�������ַ��Ҫ�õ��ݹ�
// ��һ����Ĳ��������BFS()����û���õ��ݹ�