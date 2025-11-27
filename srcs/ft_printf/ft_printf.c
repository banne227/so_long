/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banne <banne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 16:08:16 by banne             #+#    #+#             */
/*   Updated: 2025/10/28 10:21:14 by banne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	choix_format(va_list args, const char c)
{
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (c == 'u')
		return (ft_putunbr(va_arg(args, unsigned int)));
	if (c == 'p')
		return (ft_putptr(va_arg(args, void *)));
	if (c == 'x')
		return (ft_puthex(va_arg(args, unsigned int), 0));
	if (c == 'X')
		return (ft_puthex(va_arg(args, unsigned int), 1));
	if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(ap, format);
	if (!format)
		return (0);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			count += choix_format(ap, format[i + 1]);
			i += 2;
		}
		else
		{
			count += ft_putchar(format[i]);
			i++;
		}
	}
	va_end(ap);
	return (count);
}

//int main(void)
//{ 
//    printf("\n=================== TESTS ft_printf ============\n");

//    // Test %c
//    printf("\n   --TEST-- %%c:\n");
//    printf("%d\n\n", printf("printf    : %c \nsize ", 'A'));
//    printf("%d\n\n", printf("ft_printf : %c \nsize ", 'A'));

//	// Test %s
//    printf("\n   --TEST-- %%s:\n");
//    printf("%d\n\n", printf("printf    : %s \nsize ", "Hello"));
//    printf("%d\n\n", printf("ft_printf : %s \nsize ", "Hello"));

//	// Test %d
//	printf("\n   --TEST-- %%d:\n");
//    printf("%d\n\n", printf("printf    : %d \nsize ", 42));
//    printf("%d\n\n", printf("ft_printf : %d \nsize ", 42));

//		// Test %p
//	printf("\n   --TEST-- %%p:\n");
//	int a = 10;
//	printf("%d\n\n", printf("printf    : %p \nsize ", (void*)&a));
//	printf("%d\n\n", printf("ft_printf : %p \nsize ", (void*)&a));

//		// Test %u
//	printf("\n   --TEST-- %%u:\n");
//	printf("%d\n\n", printf("printf    : %u \nsize ", 3000000000u));
//	printf("%d\n\n", printf("ft_printf : %u \nsize ", 3000000000u));

//		// Test %x
//	printf("\n   --TEST-- %%x:\n");
//	printf("%d\n\n", printf("printf    : %x \nsize ", 255));
//	printf("%d\n\n", printf("ft_printf : %x \nsize ", 255));

//	// Test %X
//	printf("\n   --TEST-- %%X:\n");
//	printf("%d\n\n", printf("printf    : %X \nsize ", 255));
//	printf("%d\n\n", printf("ft_printf : %X \nsize ", 255));

//	// Test %%
//	printf("\n   --TEST-- %%%%:\n");
//	printf("%d\n\n", printf("printf    : %% \nsize "));
//	printf("%d\n\n", printf("ft_printf : %% \nsize "));

//    return (0);
//}
