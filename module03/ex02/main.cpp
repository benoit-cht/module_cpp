/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 10:41:39 by bchallat          #+#    #+#             */
/*   Updated: 2025/10/13 10:41:42 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main() {
    FragTrap frag("Fraggy");
    frag.attack("Target");
    frag.takeDamage(20);
    frag.beRepaired(10);
    frag.highFivesGuys();
    return 0;
}
