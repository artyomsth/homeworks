var
    s: string;
    a, b, c: string;
    sign1, sign2: char;
    res: integer;
    i: byte;
    bool: boolean;

begin
    writeln('Welcome to string calculator!');
    writeln('Enter expression with 3 nums and 2 operations');
    writeln('Type "exit" to stop program');
    
    while(true) do
    begin
        i := 1;
        res := 0;
        writeln;
        write('  Problem: ');
        readln(s);
        if s = 'exit' then break;
        
        while (true) do
        begin
            if s[i] in ['+', '-', '*', '/'] then
            begin
                a := copy(s, 1, i - 1);
                sign1 := s[i];
                delete(s, 1, i);
                break;
            end;
            i += 1;
        end;
        
        i := 1;
        
        while (true) do
        begin
            if s[i] in ['+', '-', '*', '/'] then
            begin
                b := copy(s, 1, i - 1);
                sign2 := s[i];
                c := copy(s, i + 1, length(s));
                break;
            end;
            i += 1;
        end;
        
        s := nil;
        s += a + sign1 + b + sign2 + c;
        bool := (((sign1 = '+') or (sign1 = '-')) and ((sign2 = '*') or (sign2 = '/')));
        
        case (bool) of
            true:   
                begin
                    case sign2 of
                        '*': res := StrToInt(b) * StrToInt(c);
                        '/': res := StrToInt(b) div StrToInt(c);
                    end;
                    case sign1 of
                        '+': res += StrToInt(a);
                        '-': res := StrToInt(a) - res;
                    end;
                end;
            false: 
                begin
                    case sign1 of
                        '+': res := StrToInt(a) + StrToInt(b);
                        '-': res := StrToInt(a) - StrToInt(b);
                        '*': res := StrToInt(a) * StrToInt(b);
                        '/': res := StrToInt(a) div StrToInt(b);
                    end;
                    case sign2 of
                        '+': res += StrToInt(c);
                        '-': res -= StrToInt(c);
                        '*': res *= StrToInt(c);
                        '/': res := res div StrToInt(c);
                    end;
                end;
        end;
        
        writeln('  Result: ', res);
    end;
end.