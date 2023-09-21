/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 23:29:54 by rgallego          #+#    #+#             */
/*   Updated: 2023/09/21 23:40:18 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;

static int	getNbAccounts( void )
{
	return (_nbAccounts);
}

static int	getTotalAmount( void );
static int	getNbDeposits( void );
static int	getNbWithdrawals( void );
static void	displayAccountsInfos( void );
