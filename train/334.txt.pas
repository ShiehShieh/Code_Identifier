var
 ds:array[1..200000] of longint;
 l1,l2,l,i,j:longint;
 n1,n2:array[1..10000] of longint;
 a:ansistring;
begin
 readln(a);
 l1 := length(a);
 for i := 1 to l1 do n1[i] := ord(a[l1-i+1]) - ord('0');
 readln(a);
 l2 := length(a);
 for i := 1 to l2 do n2[i] := ord(a[l2-i+1]) - ord('0');
 for i := 1 to l1 do
 begin
  for j := 1 to l2 do ds[i+j-1] := n1[i]*n2[j] + ds[i+j-1];
 end;
 for i := 1 to (l1 + l2) do
 begin
  ds[i+1] := (ds[i] div 10) + ds[i+1];
  ds[i] := ds[i] mod 10;
 end;
 if ds[l1+l2] = 0 then l := l1 + l2 - 1
  else
 l := l1 + l2;
 for i := l downto 1 do write(ds[i]);
end.
