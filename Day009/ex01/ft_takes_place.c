/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 19:24:36 by tlee              #+#    #+#             */
/*   Updated: 2019/10/31 20:17:41 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_takes_place(int hour)
{
	if (hour >= 0 && hour <= 10)
		printf("THE FOLLOWING TAKES PLACE BETWEEN 0%d.00 A.M. AND 0%d.00 A.M.\n"
		, hour, hour + 1);
	else if (hour == 11)
		printf("THE FOLLOWING TAKES PLACE BETWEEN %d.00 A.M. AND 12.00 P.M.\n"
		, hour);
	else if (hour >= 12 && hour <= 22)
		printf("THE FOLLOWING TAKES PLACE BETWEEN %d.00 P.M. AND %d.00 P.M.\n"
		, hour, hour + 1);
	else if (hour == 23)
		printf("THE FOLLOWING TAKES PLACE BETWEEN %d.00 P.M. AND 00.00 A.M.\n"
		, hour);
	if (hour == 24)
		printf("%s"
		, "THE FOLLOWING TAKES PLACE BETWEEN 00.00 A.M. AND 01.00 A.M.\n");
}
