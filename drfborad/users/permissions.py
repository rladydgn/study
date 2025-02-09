from rest_framework import permissions


class CustomReadOnly(permissions.BasePermission):
    # 수정할 때
    def has_object_permission(self, request, view, obj):
        # 데이터에 영향을 미치지 않는 메서드는 True 리턴, ex) GET
        if request.method in permissions.SAFE_METHODS:
            return True
        return obj.user == request.user
