#include <stdio.h>
#include "LunchPlacePicker.h"

int main(int argc, char* argv[])
{
	init("lunch-place-info.txt");
	modify(1, "������", "�����屹�� ���뱹�� ���ÿ�!");
	remove(2);
	exit();
	return 0;
}