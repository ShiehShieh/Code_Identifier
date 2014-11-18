var
  n:dword;
begin
  readln(n);
  writeln( (n shr 16) or (n shl 16) );
end.

