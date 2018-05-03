#include "ft_printf.h"

t_handler			fpf_ptrget(int id)
{
	const t_handler	handlers[FT_CONVCNT] = {
		fpf_handle_str, fpf_handle_lst, fpf_handle_ptr, fpf_handle_dec,
		fpf_handle_bde, fpf_handle_dec, fpf_handle_uns, fpf_handle_bun,
		fpf_handle_uns, fpf_handle_bun, fpf_handle_uns, fpf_handle_uns,
		fpf_handle_char, fpf_handle_bch, fpf_handle_pct, fpf_handle_bin,
		fpf_handle_bin, fpf_handle_n, fpf_handle_flo,
		fpf_handle_flo, fpf_handle_exp, fpf_handle_exp
	};

	if (id < 0 || id >= FT_CONVCNT)
		return (NULL);
	return (handlers[id]);
}
