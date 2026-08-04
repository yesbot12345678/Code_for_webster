
import math


def get_number(prompt):
    while True:
        try:
            s = input(prompt)
            if s.strip() == '':
                print('Please enter a number.')
                continue
            # Try integer first for cleaner factoring behavior
            if '.' in s or 'e' in s or 'E' in s:
                return float(s)
            return int(s)
        except Exception:
            print('Invalid number, try again.')


def int_divisors(n):
    n = int(n)
    if n == 0:
        return [0]
    ds = set()
    an = abs(n)
    i = 1
    while i * i <= an:
        if an % i == 0:
            ds.add(i)
            ds.add(-i)
            ds.add(an // i)
            ds.add(-(an // i))
        i += 1
    return sorted(ds)


def format_term(coef, var='x'):
    if coef == 0:
        return '0'
    if coef == 1:
        return var
    if coef == -1:
        return '-' + var
    return str(coef) + var


def format_binomial(a_coef, b_const):
    # a_coef * x + b_const
    term = ''
    if a_coef == 1:
        term = 'x'
    elif a_coef == -1:
        term = '-x'
    else:
        term = str(a_coef) + 'x'
    if b_const > 0:
        return '(' + term + ' + ' + str(b_const) + ')'
    elif b_const < 0:
        return '(' + term + ' - ' + str(abs(b_const)) + ')'
    else:
        return '(' + term + ')'


def try_integer_factor(a, b, c):
    # Find integers d,f,e,g such that (d x + e)(f x + g) = a x^2 + b x + c
    # d*f = a, e*g = c, d*g + e*f = b
    if a == 0:
        return None
    for d in int_divisors(a):
        f = a // d
        for e in int_divisors(c):
            if e == 0 and c != 0:
                continue
            if e == 0 and c == 0:
                g = 0
            else:
                g = c // e
            if d * g + e * f == b:
                return (d, e, f, g)
    return None


def quadratic_roots(a, b, c):
    if a == 0:
        if b == 0:
            return None
        return (-c / b,)
    disc = b * b - 4 * a * c
    if disc >= 0:
        s = math.sqrt(disc)
        r1 = (-b + s) / (2 * a)
        r2 = (-b - s) / (2 * a)
        return (r1, r2)
    else:
        s = math.sqrt(-disc)
        real = -b / (2 * a)
        imag = s / (2 * a)
        return (complex(real, imag), complex(real, -imag))


def main():
    print('Factor quadratic: a x^2 + b x + c')
    a = get_number('Enter a: ')
    b = get_number('Enter b: ')
    c = get_number('Enter c: ')

    # Handle linear / degenerate cases
    if a == 0:
        if b == 0:
            print('Not an equation (a and b are both zero).')
            return
        # bx + c => factor out b: b*(x + c/b)
        root = -c / b
        if c == 0:
            print('Factorization: x')
        else:
            print('Linear: {}*(x {:+g})'.format(b, root))
        return

    # Try integer factoring when a,b,c are integers
    if isinstance(a, int) and isinstance(b, int) and isinstance(c, int):
        res = try_integer_factor(a, b, c)
        if res:
            d, e, f, g = res
            # Normalize signs so factors display with positive leading x when possible
            if a > 0 and d < 0 and f < 0:
                d, e, f, g = -d, -e, -f, -g
            s = format_binomial(d, e) + format_binomial(f, g)
            print('Factors (integer):', s)
            return

    # Fallback: use roots
    roots = quadratic_roots(a, b, c)
    if roots is None:
        print('Cannot determine roots.')
        return
    if len(roots) == 1:
        r = roots[0]
        print('Linear root: x =', r)
        return

    r1, r2 = roots
    # If roots are real and nice, show factorization a*(x - r1)*(x - r2)
    def fmt_r(r):
        if isinstance(r, complex):
            return str(r)
        # Try to print integer if close
        if abs(r - round(r)) < 1e-9:
            return str(int(round(r)))
        return ('{:.6g}'.format(r)).rstrip('0').rstrip('.')

    if isinstance(r1, complex) or isinstance(r2, complex):
        print('Complex roots: {} and {}'.format(r1, r2))
        print('Cannot factor over the reals.')
        return

    # If both roots are rational/integer, we can show as (x - r1)(x - r2) times a
    print('Roots: {}, {}'.format(fmt_r(r1), fmt_r(r2)))
    if abs(round(r1) - r1) < 1e-9 and abs(round(r2) - r2) < 1e-9:
        # integer roots
        r1i = int(round(r1))
        r2i = int(round(r2))
        print('Factors: {}*(x {:+d})*(x {:+d})'.format(a, -r1i, -r2i))
    else:
        print('Factorization (using roots): {}*(x {:+g})*(x {:+g})'.format(a, -r1, -r2))


if __name__ == '__main__':
    main()
