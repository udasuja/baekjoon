/*
L->커서를 왼쪽으로 한 칸 옮김 (커서가 문장의 맨 앞이면 무시됨)
D->커서를 오른쪽으로 한 칸 옮김 (커서가 문장의 맨 뒤이면 무시됨)
B->커서 왼쪽에 있는 문자를 삭제함 (커서가 문장의 맨 앞이면 무시됨)
삭제로 인해 커서는 한 칸 왼쪽으로 이동한 것처럼 나타나지만, 
실제로 커서의 오른쪽에 있던 문자는 그대로임
P $->$라는 문자를 커서 왼쪽에 추가함

예제:
	입력
	abcd
	3
	P x     ->top이 4번째 인덱스를 가리키고 거기에 x를 집어넣는다. 그리고 top값을 1증가시킨다. 
	L		->top은 5번째 인덱스를 가리키다가 3번째 인덱스를 가리킨다.
	P y		->top은 4번째 인덱스를 가리키는데 거기에는 x가 저장되었다.
			  그러므로 x를 오른쪽으로 한 칸 옮기고 빈자리에 y를 저장
	출력
	abcdyx


	입력
	abc
	9
	L->top은 3을 저장했는데 L 때문에 2를 저장
	L->top은 1를 저장
	L->top은 0을 저장
	L->top은 -1를 저장하여 왼쪽 끝에 다달았다는 것을 의미함
	L->여전히 top은 -1이다.
	P x->top은 -1이므로 0번째부터 모든 문자를 오른쪽으로 한 칸 옮긴다.
		 그리고 0번째에 x를 집어넣고 top를 1증가시킨다.
	L ->top은 0이므로 -1로 만든다.
	B ->top이 -1이므로 아무것도 제거되지 않는다.
	P y -> top은 -1이므로 0번째 이후 문자를 오른쪽으로 옮기고, 0번째에 문자를 넣는다.
	출력
	yxabc

	입력
	dmih
	11
	B  ->dmi
	B  ->dm
	P x->dmx
	L  ->top은 m를 가리킴
	B  ->dx
	B  ->x
	B  ->x
	P y->yx
	D   
	D
	P z

	출력
	yxz

연결리스트를 사용한 스택을 구현하여 이 문제를 풀 수 있을 것이라고 생각한다.(dmih가 입력되었다면 h가 스택 상단에 위치, d가 스택 하단에 위치)
L과 D가 나오면 top값을 각각 1더하고, 1빼는 식으로 연산을 지속하고
B나 P가 나오면 그 top값 만큼 연결리스트에 들어가며 top위치에 값을 제거하거나 그 위치에 문자를 추가한다. 

이때 top구초체는 몇 번째 node를 가리키고 있는지에 대한 정수값과 그 node에 대한 주소값을 저장한다.
node는 앞뒤 node 모두 가리키고, L이 입력되면 top-- 후 뒤에 node를 가리킨다. 만약 뒤에 node가 null이면 top에는 -1이 저장


*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	char c;
	struct node* left;
	struct node* right;
}node;

typedef struct 
{
	node* top_node;
	int top_int;
}Top;

int main(void)
{
	node last = { '\0',NULL,NULL };//마지막 node
	node first = { '\0',NULL,&last };//첫번째 node
	Top top = { &first,-1 };
	int n;
	char ch;
	last.left = &first;//마지막 node의 left는 first를 가리키도록 함

	while ((ch = getchar()) != '\n')
	{
		node* new_node = (node*)malloc(sizeof(node));
		node* last_l = last.left;
		new_node->c = ch;
		new_node->left = last_l;
		new_node->right = &last;
		last.left = new_node;
		last_l->right = new_node;
		top.top_int += 1;
		top.top_node = new_node;
	}
	//top.top_int는 위 반복문으로 추가된 'node의 개수-1개'의 값을 저장한다.

	scanf("%d", &n);
	getchar();
	while (n--)
	{
		char comm[5];
		fgets(comm, 5, stdin);

		switch (comm[0])
		{
		case 'L':
			if (top.top_int != -1)//가장 왼쪽이 아니라면
			{
				top.top_int -= 1;//top_int에 1를 빼고
				top.top_node = (top.top_node)->left;//왼쪽 node를 가리키도록 함
			}
			break;
		case 'D':
			if ((top.top_node)->right != &last)//top.top_node의 right가 가리키는 node가 last가 아니면
			{
				top.top_int += 1;
				top.top_node = (top.top_node)->right;
			}
			break;
		case 'B':
			if (top.top_node != &first)//top_int가 -1이면 맨 왼쪽에 있으므로 왼쪽 node를 삭제할 수 없다.
			{
				node* left_n = (top.top_node)->left;//left_n은 삭제할려는 node 왼쪽 node를 가리킨다.
				node* right_n = (top.top_node)->right;//right_n은 삭제할려는 node 오른쪽 node를 가리킨다.
				right_n->left = left_n;//A B C 노드들이 이런 순으로 연결되있으면 C node의 left가 B가 아닌 A를 가리키게 된다.
				left_n->right = right_n;//A node의 right가 B가 아닌 C를 가리키게 된다.
				free(top.top_node);
				top.top_int -= 1;//B node가 삭제되고 top은 A를 가리키도록 한다.
				top.top_node = left_n;
			}
			break;
		case 'P':
		{
			node* new_node = (node*)malloc(sizeof(node));
		
			//A B 노드들이 이런 순으로 연결되어있다. 이때 C node를 A와 B사이에 추가한다.
			node* last_n = (top.top_node)->right;//B node, top.top_node는 last이전까지만 저장되기에 right는 null이 무조건 아니다.
			new_node->c = comm[2];
			new_node->left = last_n->left;//C의 left가 A를 가리키도록 함
			new_node->right = last_n;//C의 right가 B를 가리키도록 함
			(last_n->left)->right = new_node;//A의 right가 C를 가리키도록 함
			last_n->left = new_node;//B의 left가 C를 가리키도록 함
			top.top_int += 1;
			top.top_node = new_node;
			break;
		}
		}
	}
	while ((first.right) != &last)
	{
		node* temp = first.right;
		printf("%c", temp->c);
		first.right = temp->right;
		free(temp);
	}

}