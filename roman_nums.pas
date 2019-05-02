var
  s, s1, w, gonnainsert: string;
  a, num: word;
  i: integer;

begin
  i := 1;
  write('Введите строку: ');
  readln(s);
  s += ' %';
  while (s[i] <> '%') do
  begin
    w := '1';
    case s[i] of
      'I', 'V', 'X', 'L', 'C', 'D', 'M':
        begin
          num := 0;
          w := ReadWordFromString(s, i);
          for var j := 1 to length(w) do
          begin
            case w[j] of
              'I': a := 1;
              'V': a := 5;
              'X': a := 10;
              'L': a := 50;
              'C': a := 100;
              'D': a := 500;
              'M': a := 1000;
            end;
            num += a;
          end;
          gonnainsert := nil;
          gonnainsert += num + ' ';
          s1 += gonnainsert;
        end
    else s1 += s[i];
    end;
    i += 1;
  end;
  writeln('Римские цифры заменены: ', s1);
end.