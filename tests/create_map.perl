#!/usr/bin/perl
use warnings;
use strict;

die "program x y density" unless (scalar(@ARGV) == 6);
my ($x, $y, $density, $a, $b, $c) = @ARGV;
print "$y$a$b$c\n";
for (my $i = 0; $i < $y; $i++) {
	for (my $j = 0; $j < $x; $j++) {
		if (int(rand($y) * 2) < $density) {
			print "$b";
		}
		else {
			print "$a";
		}
	}
print "\n";
}
