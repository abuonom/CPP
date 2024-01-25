#ifndef MATERIA_HPP
# define MATERIA_HPP
# include <string>
# include <iostream>


class ICharacter;

class	AMateria
{
	protected:
		std::string		type;

	public:
		AMateria(std::string const &type);
		AMateria(const AMateria &obj);
		virtual	~AMateria(void);
		AMateria&		operator=(const AMateria &obj);
		std::string const	&getType(void) const;
		virtual AMateria*	clone(void) const = 0;
		virtual void		use(ICharacter& target);
};

class	Ice: public AMateria
{
	public:
		Ice(void);
		Ice(const Ice &obj);
		~Ice(void);
		Ice&			operator=(const Ice &obj);
		AMateria*		clone(void) const;
		void			use(ICharacter& target);
};

class	Cure: public AMateria
{
	public:
		Cure(void);
		Cure(const Cure &obj);
		~Cure(void);
		Cure&			operator=(const Cure &obj);
		AMateria*		clone(void) const;
		void			use(ICharacter& target);
};

#endif
