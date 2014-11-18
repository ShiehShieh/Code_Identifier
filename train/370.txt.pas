{
ID:shadow_3
PROG:p1063
LANG:PASCAL
}

var
	i,j,k,l,n,max:longint;
	s:array[0..500]of ansistring;
	flag:boolean;

begin


	readln(n);
	for i:=1 to n do
        begin
                readln(s[i]);
                s[i]:=s[i]+'fjaosidjfoiasodpfjadfasdfasdfasdfsadfsapdfjapogkpsdfgsdfjgpsdjospdjfasjdfjasdjfpasjidfjpoasjdifajsoidfjoaisdfasdfasdfasdfjoaisjdfopajospdfasdfsadfasdjfopiasjdofasdf';
                s[i]:=s[i]+'asdofiajsdpijaosdjfiajsdpfjiasdfjpasidjfpaodfajsodjfoapsjdfiajsodfjoisjdofjsifosidjfosjdfosdjfosdjfosjdifjosdjfosjdfijsodjfosdjfoisjdfoijsodfjoisdjofjsdifjosdjfosid';
        end;

	for i:=1 to n do
		for j:=i to n*2-i do if odd(j-i+1) then if s[i,j]='-' then
			for k:=i downto 1 do
			begin
				flag:=true;
                                for l:=j-(i-k) to j+(i-k) do if s[k,l]<>'-' then
				begin
					flag:=false;
					break;
				end;
				if not flag then
				begin
					if i-k>max then max:=i-k;
					break;
				end;
                                if k=1 then max:=i;
			end;
        for i:=1 to n do
                for j:=1 to n*2 do if not odd(j) then if s[i,j]='-' then
                        for k:=i to n do
                        begin
                                flag:=true;
                                for l:=j-(k-i) to j+(k-i) do if s[k,l]<>'-' then
                                begin
                                        flag:=false;
                                        break;
                                end;
                                if not flag then
                                begin
                                        if k-i>max then max:=k-i;
                                        break;
                                end;
                        end;

	writeln(max*max);


end.

