local a={}
local i=1
local k
--[[
-- ���ļ��ж�ȡ���ݣ�����Ϊ"#"����һ�У�����table��
for line in io.lines("data2.in") do
	if( line~="#" ) then
		a[i]=line
		i=i+1
	else
		k=i
	end
end
]]
local line
while( true ) do
	line=io.read()
	if( line~="" ) then
		if( line~="#" ) then
			a[i]=line
			i=i+1
		else
			k=i
		end
	else
		break
	end
end



for k=k,i-1 do

	-- �ж�ָ���ַ������Ƿ��С�=����û�����������
	local h
	h=string.find(a[k],"=")
	if( h==nil ) then
		print("Wrong!") -- io.open("data2.out","a+"):write("Wrong!\n")
		return
	end
	-- ��ȡ��=�����ߵ��ַ���

	local l
	local r

	l=string.sub(a[k],1,h-1)
	r=string.sub(a[k],h+1,string.len(a[k]))

	-- ���ָ���Ƿ�Ϸ�
	local ch={{},{},{}}
	flag=false
	for j=1,k-1 do

		for w,v,z in string.gmatch(a[j],"(%a*)%s(%a*)%((%d*)%)") do
			ch[j][1]=w  --��һ���ո�ǰ�ĵ���
			ch[j][2]=v  --���ڵ�һ���ո��Լ�������ǰ�ĵ���
			ch[j][3]=z  --�����еĵ���
			if( w==nil or z==nil ) then
				print("Wrong!")
				return
			end
			if( v~="int" and v~="char" ) then
				print("Wrong!")
				return
			end
			--���ָ����ߵĵ��ʺ�wƥ��
			if( w==l ) then
				if( v=="char" ) then
					--��һ���ַ������һ���ַ������������������
					if( string.sub(r,1,1)~="\"" and string.sub(r,string.len(r),string.len(r))~="\"" ) then
						print("Wrong!")
						return
					end
					--˫�����м仹���������������
					if( string.match(string.sub(r,2,string.len(r)-1),"\"") ~=nil ) then
						print("Wrong!")
						return
					end
					--���û��ƥ��˫���ŵĵ������������
					--��������ȡ��˫�����еĵ���
					r=string.match(r,"\"(%a*)\"")
					if( r== nil ) then
						print("Wrong!")
						return
					end
					--�жϳ����Ƿ�Ϸ�
					if( string.len(r)<=tonumber(z) ) then
						--break
						--io.open("data2.out","a+"):write("Right!\n")
						--return
						flag=true
					else
						print("Wrong!")
						return
					end

				-- v=="int"ʱ
				else
					--�з������ַ��������������
					if( string.match(r,"%D")~=null ) then
						print("Wrong!")
						return
					end
					if( string.len(r)<=tonumber(z) ) then
						--break
						--io.open("data2.out","a+"):write("Right!\n")
						--return
						flag=true
					else
						print("Wrong!")
						return
					end
				end

			end

		end

	end

	if(flag==false) then
		--����Ҳ�����ָ����ߵĵ�����ƥ��������������
		print("Wrong!")
		return
	end

end

print("Right!")
return

