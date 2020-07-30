/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bqs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 13:19:35 by tlee              #+#    #+#             */
/*   Updated: 2019/11/13 17:16:46 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//저장할 위치와 크기변수 공간
//인덱스 형식을 확인한 뒤 장애물을 0으로 변환
//가장 오른쪽에서 아래쪽 한칸 대각선 앞에서 시작
//오른쪽과 아래두쪽 칸을 비교하여 가장작은수에서 +1
//크거나 같은 수가 등장하는 경우 위치를 저장하고 크기 또한 저장
//위치가 frame[1][0]까지 도달하였을 경우 마지막 실행뒤 종료.
//해당 프레임을 출력할 함수 생성.

//출력함수
//비교함수 (저장까지)
//함수 반복

#include <unistd.h>

char	g_obstacle;
char	g_full;
char	g_empty;

char	**ready(char **frame)
{
	int i;
	int j;

	i = 0;
	while (frame[0][i] == '\n')
		i++;
	g_full = frame[0][i - 1];
	g_obstacle = frame[0][i - 2];
	g_empty = frame[0][i - 3];
	i = 0;
	j = -1;
	while (frame[++i])
	{
		while (frame[i][++j] != '\n')
		{
			if (frame[i][j] == g_obstacle)
				frame[i][j] = '0';
			else
				frame[i][j] = '1';
		}
		j = -1;
	}
	return (frame);
}

char	set_num(char **frame, int lo_row, int lo_col)
{
	char	i;

	if (frame[lo_row + 1][lo_col + 1] <= frame[lo_row + 1][lo_col])
		i = frame[lo_row + 1][lo_col + 1];
	else
		i = frame[lo_row + 1][lo_col];
	if (i <= frame[lo_row][lo_col + 1])
		;
	else
		i = frame[lo_row][lo_col + 1];
	return (i + 1);
}

char	**frame_location(char **frame)
{
	int row;
	int col;
	int i;
	int j;

	row = 0;
	col = 0;
	while (frame[row])
		row++;
	while (frame[1][col] != '\n')
		col++;
	i = row;
	j = col;
	while (--i > 0)
	{
		while (--j > -1)
			if (frame[i][j] != '0')
				frame[i][j] = set_num(frame, i, j);
		j = col;
	}
	return (frame);
}

void	print_frame(char **frame)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (frame[i])
	{
		while (frame[i][j] != '\n')
		{
			if (frame[i][j] == '0')
				write(1, &g_obstacle, 1);
			else if (frame[i][j] >= '1' && frame[i][j] <= '9')
				write(1, &g_empty, 1);
			else
				write(1, &frame[i][j], 1);
		}
		write(1, "\n", 1);
		j = 0;
	}
}

void	bsq(char **frame, int i)
{
	int		j;
	char	save_num;
	int		save_lo[2];

	frame = frame_location(ready(frame));
	j = -1;
	save_num = '0';
	while (frame[++i])
	{
		while (frame[i][++j] == '\n')
			if (frame[i][j] >= save_num)
			{
				save_lo[0] = i;
				save_lo[1] = j;
				save_num = frame[i][j];
			}
		j = -1;
	}
	i = -1;
	j = -1;
	while (++i < save_num)
		while (++j < save_num)
			frame[save_lo[0]++ - 1][save_lo[1]++ - 1] = g_full;
	print_frame(frame);
}
