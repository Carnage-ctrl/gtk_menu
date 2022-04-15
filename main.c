#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include "page.h"

int main(int argc, char *argv[])
{
	/*  Inicialização do GTK */
	gtk_init(&argc, &argv);
	/*  Configurando Variaveis Anteriormente Definidas (page.h) */
	Window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	Box = gtk_box_new(1, TRUE);
	MenuBar = gtk_menu_bar_new();
	SettingsMenu = gtk_menu_new();
	SettingsMenuItem = gtk_menu_item_new_with_label("Settings");
	SettingsMenuCloseItem = gtk_menu_item_new_with_label("Exit");
	/*  Configurando Menu, Window, Containers e Box */
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(SettingsMenuItem), SettingsMenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(SettingsMenu), SettingsMenuCloseItem);
	gtk_menu_shell_append(GTK_MENU_SHELL(MenuBar), SettingsMenuItem);
	gtk_container_add(GTK_CONTAINER(Window), Box);
	gtk_box_pack_start(GTK_BOX(Box), MenuBar, FALSE, FALSE, 0);
	gtk_widget_set_size_request(GTK_WIDGET(Window), 400, 200);
	gtk_window_set_title(GTK_WINDOW(Window), "GTK+3 is so powerful!");
	gtk_window_set_resizable(GTK_WINDOW(Window), FALSE);
	/*  Widget e Eventos */
	gtk_widget_show_all(Window);
	g_signal_connect(G_OBJECT(SettingsMenuCloseItem), "activate", G_CALLBACK(encerrar), NULL);
	gtk_main(); // Loop do programa e escuta de eventos
	return 0;
}

extern void encerrar()
{
	Dialog = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, 
			GTK_BUTTONS_OK, "Encerrando o programa...");

	gtk_dialog_run(GTK_DIALOG(Dialog));
	gtk_widget_destroy(Dialog);

	gtk_main_quit();
}
