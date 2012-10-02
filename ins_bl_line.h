/**
 * This function inserts a blank line after each 'n' lines 
 *
 * \param	n		no. of lines after which to insert a blank line
 * \param	sp_read		stream pointer to source file
 * \param	sp_write	stream pointer to target file
 *
 * \return	count_ins	count of lines inserted
 * */

int ins_bl_line(int n, FILE* sp_read, FILE* sp_write)
{
	/* Local Declarations */
	char	ch;
	int	count_lines = 0;
	int	count_lines_inserted = 0;
	int	count_ins;
	
	while ((ch=fgetc(sp_read)) != EOF)
	{
		if (ch == '\n')
		{
			count_lines++;
			count_ins = 0;
			while (count_ins <= n)
			{
				fputc('\n', sp_write);
				count_lines_inserted++;
				count_ins++;
			}
		}
		else
			fputc(ch, sp_write);
	}

	count_lines_inserted = count_lines_inserted - count_lines;

	/* Exit Program */
	return count_lines_inserted;
}
