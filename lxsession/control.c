/* control.c generated by valac 0.34.7, the Vala compiler
 * generated from control.vala, do not modify */

/* 
 *      Copyright 2012 Julien Lavergne <gilir@ubuntu.com>
 *
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 2 of the License, or
 *      (at your option) any later version.
 *
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *
 *      You should have received a copy of the GNU General Public License
 *      along with this program; if not, write to the Free Software
 *      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 *      MA 02110-1301, USA.
 */
/* TODO Implement multiple request by using the inhib_cookie in a array
        and to remove the cookie when the application request it
*/

#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>


#define LXSESSION_TYPE_CONTROL_OBJECT (lxsession_control_object_get_type ())
#define LXSESSION_CONTROL_OBJECT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), LXSESSION_TYPE_CONTROL_OBJECT, LxsessionControlObject))
#define LXSESSION_CONTROL_OBJECT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), LXSESSION_TYPE_CONTROL_OBJECT, LxsessionControlObjectClass))
#define LXSESSION_IS_CONTROL_OBJECT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), LXSESSION_TYPE_CONTROL_OBJECT))
#define LXSESSION_IS_CONTROL_OBJECT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), LXSESSION_TYPE_CONTROL_OBJECT))
#define LXSESSION_CONTROL_OBJECT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), LXSESSION_TYPE_CONTROL_OBJECT, LxsessionControlObjectClass))

typedef struct _LxsessionControlObject LxsessionControlObject;
typedef struct _LxsessionControlObjectClass LxsessionControlObjectClass;
typedef struct _LxsessionControlObjectPrivate LxsessionControlObjectPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))

struct _LxsessionControlObject {
	GObject parent_instance;
	LxsessionControlObjectPrivate * priv;
};

struct _LxsessionControlObjectClass {
	GObjectClass parent_class;
};


static gpointer lxsession_control_object_parent_class = NULL;

GType lxsession_control_object_get_type (void) G_GNUC_CONST;
enum  {
	LXSESSION_CONTROL_OBJECT_DUMMY_PROPERTY
};
void lxsession_control_object_set_status_busy (LxsessionControlObject* self, guint toplevel_xid);
void lxsession_control_object_inhib_screensaver (LxsessionControlObject* self, guint toplevel_xid);
void lxsession_control_object_exit_status_busy (LxsessionControlObject* self);
void lxsession_control_object_uninhibit_screensaver (LxsessionControlObject* self);
void lxsession_lxsession_spawn_command_line_async (const gchar* command_line);
LxsessionControlObject* lxsession_control_object_new (void);
LxsessionControlObject* lxsession_control_object_construct (GType object_type);


void lxsession_control_object_set_status_busy (LxsessionControlObject* self, guint toplevel_xid) {
	guint _tmp0_ = 0U;
	g_return_if_fail (self != NULL);
	_tmp0_ = toplevel_xid;
	lxsession_control_object_inhib_screensaver (self, _tmp0_);
}


void lxsession_control_object_exit_status_busy (LxsessionControlObject* self) {
	g_return_if_fail (self != NULL);
	lxsession_control_object_uninhibit_screensaver (self);
}


void lxsession_control_object_inhib_screensaver (LxsessionControlObject* self, guint toplevel_xid) {
	gchar* create_command = NULL;
	guint _tmp0_ = 0U;
	gchar* _tmp1_ = NULL;
	gchar* _tmp2_ = NULL;
	gchar* _tmp3_ = NULL;
	gchar* _tmp4_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = toplevel_xid;
	_tmp1_ = g_strdup_printf ("%u", _tmp0_);
	_tmp2_ = _tmp1_;
	_tmp3_ = g_strconcat ("xdg-screensaver suspend" " ", _tmp2_, NULL);
	_tmp4_ = _tmp3_;
	_g_free0 (_tmp2_);
	create_command = _tmp4_;
	lxsession_lxsession_spawn_command_line_async (create_command);
	g_message ("control.vala:43: Inhib Screensaver");
	_g_free0 (create_command);
}


void lxsession_control_object_uninhibit_screensaver (LxsessionControlObject* self) {
	g_return_if_fail (self != NULL);
	lxsession_lxsession_spawn_command_line_async ("xdg-screensaver reset");
	g_message ("control.vala:49: Disable Inhib Screensaver");
}


LxsessionControlObject* lxsession_control_object_construct (GType object_type) {
	LxsessionControlObject * self = NULL;
	self = (LxsessionControlObject*) g_object_new (object_type, NULL);
	return self;
}


LxsessionControlObject* lxsession_control_object_new (void) {
	return lxsession_control_object_construct (LXSESSION_TYPE_CONTROL_OBJECT);
}


static void lxsession_control_object_class_init (LxsessionControlObjectClass * klass) {
	lxsession_control_object_parent_class = g_type_class_peek_parent (klass);
}


static void lxsession_control_object_instance_init (LxsessionControlObject * self) {
}


GType lxsession_control_object_get_type (void) {
	static volatile gsize lxsession_control_object_type_id__volatile = 0;
	if (g_once_init_enter (&lxsession_control_object_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (LxsessionControlObjectClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) lxsession_control_object_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (LxsessionControlObject), 0, (GInstanceInitFunc) lxsession_control_object_instance_init, NULL };
		GType lxsession_control_object_type_id;
		lxsession_control_object_type_id = g_type_register_static (G_TYPE_OBJECT, "LxsessionControlObject", &g_define_type_info, 0);
		g_once_init_leave (&lxsession_control_object_type_id__volatile, lxsession_control_object_type_id);
	}
	return lxsession_control_object_type_id__volatile;
}



