#ifndef __TANK_H__
#define __TANK_H__

#include <assert.h>
#include <graphics.h>

#define ROWS		26
#define COLS		26
#define TANK_POSITION_X	8
#define TANK_POSITION_Y	24

/* ��ͼ�Ķ�ά������map.h�ж��� */
extern int map[ROWS][COLS];

/* ̹���ƶ��ķ��� */
enum DIRECTION { UP, DOWN, LEFT, RIGHT };

struct tank_s {
	int x;			// ̹���ڵ�ͼ������
	int y;
	int live;		// ̹���Ƿ����棺1(����) 0(����)
	DIRECTION dir;
};

/* ��ʾ��Ϸ��ʼ�Ľ��� */
void menu();

/* ������������¼�����˵������ʼ����������Ӧ */
void captureMouse();

/*
 * ��ʼ����ͼ
 *
 *        map�� Ҫ��ʼ���ĵ�ͼ�������ͼ������׵�ַ������: &map[0][0]
 * rows, cols�� ��ͼ������������
 */
void init_map(int *map, int rows, int cols);

/*
 * �ڵ�ͼ�ϱ����ս̹�˳�ʼ����λ��
 *
 *  map:	��ͼ���׵�ַ��&map[0][0]
 * x, y: ��ս̹�˳�ʼ����λ������
 * flag: ��ս̹�˵ı��Ϊ200
 */
void set_prop_map(int *map, int x, int y, int flag);

/*
 * ��ʼ����ս̹��
 *
 * x��y: ��ս̹���ڵ�ͼ���ֵ�����
 */
void init_tank(int x, int y);

#endif // !__TANK_H__
