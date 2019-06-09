#ifndef __TANK_H__
#define __TANK_H__

#include <graphics.h>

#define ROWS		26
#define COLS		26


/*
 * ��ʾ��Ϸ��ʼ�Ľ���
 */
void menu();

/*
 * ������������¼�����˵������ʼ����������Ӧ
 */
void captureMouse();

/*
 * ��ʼ����ͼ
 *
 *        map�� Ҫ��ʼ���ĵ�ͼ�������ͼ������׵�ַ������: &map[0][0]
 * rows, cols�� ��ͼ������������
 */
void init_map(int *map, int rows, int cols);

#endif // !__TANK_H__
