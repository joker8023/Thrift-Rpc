from database import r

def auth(device_uuid,access_token):
    """
    auth
    :param device_uuid:
    :param access_token:
    :return: True or False
    """
    _access_token = r.get(device_uuid)
    return  _access_token == access_token