Status InitList(LinkList &L)
{
	//����һ���յĵ�����L
	L = new LNode;
	L->next = Null;
	return ok;
}
typedef struct LNode
{
	ElemType data;
	struct LNode* next;
}LNode,*LinkList;

LinkList List_HeadInsert(LinkList &L) {//������������
	LNode* s; int x;
	L = (LinkList)malloc(sizeof(LNode));//����ͷ���
	L->next = NULL;		//��ʼΪ������
	scanf("%d", &x);	//�������ֵ
	while (x != 9999) {		//����9999��ʾ����
		s = ��LNode*)malloc(sizeof(LNode));//�����½��
		s->data = x;
		s->next = L->next;
		L->next = s;//���½�������У�LΪͷָ��
		scanf("%d", & x);
	}
	return L;
}