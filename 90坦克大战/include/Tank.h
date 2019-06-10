#ifndef __TANK_H__
#define __TANK_H__

#define ROWS		26
#define COLS		26
#define TANK_POSITION_X	8
#define TANK_POSITION_Y	24

extern int map[ROWS][COLS];				// ��ͼ�Ķ�ά������map.h�ж���

enum DIRECTION { UP, DOWN, LEFT, RIGHT };	// ̹���ƶ��ķ���

struct bullet_s
{
	int pos_x;							// �ӵ��ڵ�ͼ��x����
	int pos_y;							// �ӵ��ڵ�ͼ��y����
	int status;							// �ӵ��Ƿ����
	DIRECTION dir;						// �ӵ����еķ���
};

struct tank_s {
	int x;								// ̹���ڵ�ͼ������
	int y;
	int live;							// ̹���Ƿ����棺1(����) 0(����)
	DIRECTION dir;
	void (*fire_bullet)(bullet_s *);		// �����ӵ�
};

extern tank_s my_tank;					// ������ս̹�˽ṹ��
extern IMAGE my_tank_img[4];				// ̹���ƶ������ͼƬ



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
 * ���������ȡ�ڵ�ͼ�ϱ�ǵ�ֵ
 *
 *  map:	��ͼ���׵�ַ��&map[0][0]
 *  x,y: ��ͼ������
 */
int get_prop_map(int *map, int x, int y);

/*
 * ��ʼ����ս̹��
 *
 * x��y: ��ս̹���ڵ�ͼ���ֵ�����
 */
void init_tank(int x, int y);

/*
 * ̹���ƶ�
 *
 * tank: Ҫ�ƶ���̹��
 *  dir: �ƶ��ķ���
 *  img: ̹���ƶ������ͼƬ
 */
void tank_walk(tank_s *tank, DIRECTION dir, IMAGE *img);

#endif // !__TANK_H__
