#include"word.h"
TkWord *tk_hashtable[MAXKEY];
DynArray tktable;
//�ַ�hash��ʽ
int elf_hash(char *key) {
	int h = 0, g;
	while (*key) {
		h = (h << 4) + *key++;
		g = h & 0xf0000000;
		if (g) {
			h ^= g >> 24;
		}
		h &= ~g;
	}
	return h% MAXKEY;
}
//��ʼ����̬�ַ�����������
void dynstring_init(DynString* pstr, int initsize) {
	if (pstr != NULL) {
		pstr->data = (char*)malloc(sizeof(char)*initsize);
		pstr->count = 0;
		pstr->capacity = initsize;
	}
}//�ͷŶ�̬�ַ���ʹ�õ��ڴ�Ŀռ�
void dynstring_free(DynString* pstr) {
	if (pstr != NULL) {
		if (pstr->data) {
			free(pstr->data);
		}
		pstr->count = 0;
		pstr->capacity = 0;
	}
}
//���ö�̬�ַ��������ͷţ����³�ʼ��
void dynstring_reset(DynString *pstr) {
	dynstring_free(pstr);
	dynstring_init(pstr, 8);
}
//���·����ַ�������
void dynstring_realloc(DynString* pstr, int new_size) {
	int capacity;
	char *data;
	capacity = pstr->capacity;
	while (capacity < new_size) {
		capacity *= 2;
	}
	data = realloc(pstr->data, capacity);
	if (!data) {
		printf("�ڴ����ʧ��");
	}
		pstr->capacity = capacity;
		pstr->data = data;
}
//׷�ӵ����ַ�����̬�ַ�������
void dynstring_chcat(DynString* pstr, int ch) {
	int count;
	count = pstr->count + 1;
	if (count > pstr->capacity) {
		dynstring_realloc(pstr, count);
	}
	pstr->data[count - 1] = ch; //û����ǿ������ת����char *��������ע��
	pstr->count = count;
}


//�ڵ��ʱ���ҵ��� 
//bug:tokenδ����
TkWord* tkword_find(char *p, int keyno) {
	TkWord *tp = NULL, *tp1;
	int token;
	for (tp1 = tk_hashtable[keyno]; tp1; tp1 = tp1->next) {
		if (!strcmp(p, tp1->spelling)) {
			token = tp1->tkcode;
			tp = tp1;
		}
	}
	return tp;
}
//��ʶ�����뵥�ʱ��Ȳ��ң����Ҳ����ٲ��뵥�ʱ�
TkWord* tkword_insert(char *p) {
	TkWord *tp;
	int keyno;
	char *s;
	char *end;
	int length;
	keyno = elf_hash(p);
	tp = tkword_find(p, keyno);
	if (NULL == tp) {
		length = strlen(p);
		tp = (TkWord*)mallocz(sizeof(TkWord) + length + 1);
		tp->next = tk_hashtable[keyno];
		tk_hashtable[keyno] = tp;
		dynarray_add(&tktable, tp);
		tp->tkcode = tktable.count - 1;
		s = (char *)tp + sizeof(TkWord);
		tp->spelling = (char *)s;
		for (end = p + length; p < end;)
		{
			*s++ = *p++;
		}
		*s = (char) '\0';

		tp->sym_identifier = NULL;
		tp->sym_struct = NULL;
	}
	return tp;
}
//��������ؼ��֡�����ֱ�ӷ��뵥�ʱ�
TkWord *tkword_direct_insert(TkWord* tp) {
	int keyno;
	dynarray_add(&tktable, tp);
	keyno = elf_hash(tp->spelling);
	tp->next = tk_hashtable[keyno];
	tk_hashtable[keyno] = tp;
	return tp;
}