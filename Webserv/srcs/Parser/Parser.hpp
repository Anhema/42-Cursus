#ifndef PARSER_HPP
# define PARSER_HPP

# include "DataContainers.hpp"
# include <fstream>
# include "BlockHandler.hpp"
# include "list"

#ifndef PARSER_UNDEFINED_MAX_TOKENS
# define PARSER_UNDEFINED_MAX_TOKENS (-1)
#endif



namespace Parser
{
	class KeysNotClosed: public std::invalid_argument
	{
	public:
		KeysNotClosed();
	};

	class Exception: public std::exception
	{
	protected:
		const string m_line;
		const string m_token;
		const int n;
		const string message;

	public:
		Exception(const std::string& line, const std::string &token, int n);

		virtual 		~Exception() throw() {}
		virtual void	print() = 0;

		const char* 	what() const throw() {
			return message.c_str();
		}
	};



	class BadCheck
	{
	public:
		BadCheck(std::string const &bad_token);
		const std::string &token;
	};

	class TooManyArguments: public Exception
	{
	public:
		TooManyArguments(const std::string &line, const int expected, const int have);
		void print();
		int m_expected;
		int m_have;
	};

	class InvalidFile: public Exception
	{
	public:
		InvalidFile(const std::string &line, const std::string &file, int n);
		void print();
	};

	class InvalidToken: public Exception
	{
	public:
		InvalidToken(const std::string &line, const std::string &token, int n);
		void print();
	};

	class InvalidValue: public Exception
	{
	public:
		InvalidValue(const std::string &line, const std::string &token, int n);
		void print();
	};

	class Reader
	{

	public:
		struct Rules
		{
			bool		useSemicolon;
			char 		bracket_opener;
			char 		bracket_closer;
            char        line_delimiter;
			std::string extension;
			char 		comment;
			std::string key_end;
		};

    private:
		struct BracketPosition
		{
			BracketPosition(int pos, int depth, std::string const &type);
			BracketPosition(struct BracketPosition const &rhs);
			~BracketPosition();
			const std::string 					                    type;
			int 								                    pos;
			int 								                    depth;
		};

	public:
		Reader();
		Reader(std::string const &file);
		Reader(Reader const &rhs);
		virtual ~Reader();

		void			setRules(Rules const &rules);

		virtual void				init() = 0;
		virtual void				start() = 0;
        virtual void                save(Data::Conf *data) = 0;

	protected:
		Rules												m_rules;
		std::ifstream										m_filestream;
		std::map<const std::string, Parser::BlockHandler *>	m_BlockHandlers;

		void						m_checkFile();
		void						m_find_bracket();
		void						m_read_bracket(std::stringstream &bracket, Data::Line const &header);
        void                        m_getBracketData(std::stringstream &dst);
        bool                        lineIsOpener(const Data::Line &line);
        bool                        lineIsCloser(const Data::Line &line);
		int 						total_depth;
		int 						total_pos;
        BracketPosition             &getPostion(int x, int y);

	private:
        typedef std::list<struct BracketPosition>::iterator BracketPositionIterator;

		std::string 										m_filename;
		std::vector<std::string>							m_lines;
		size_t 												m_current_line;
		std::list<BracketPosition>							m_bracket_positions;
		Data::Line 					strline(const string &raw);
	public:
		void						print_brackets(std::list<struct BracketPosition> &brackets, int depth);
	};
}

# endif
