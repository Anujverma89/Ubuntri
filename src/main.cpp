#include <gtk/gtk.h>
#include <iostream>

using namespace std;



static void activate(GApplication *application){
  GtkApplication *app = GTK_APPLICATION (application);
  GtkWindow *win;

  win = gtk_application_get_active_window (app);
  gtk_window_present (win);                                   
}

static void startup(GtkApplication *application){
  GtkApplication *app =   PLICATION(application);
  GtkBuilder *build;
  GtkWindow *win;

  build = gtk_builder_new_from_file("./main.ui");
  win = GTK_WINDOW(gtk_builder_get_object(build, "main_window"));
  gtk_window_set_application(win, app);

  GtkWidget *window =GTK_WIDGET(gtk_builder_get_object(build, "ubuntri_content_box"));
  gtk_widget_set_name(window, "right_content");
  GtkWidget *learnbox =GTK_WIDGET(gtk_builder_get_object(build, "learn_button_box"));
  GtkWidget *troublebox =GTK_WIDGET(gtk_builder_get_object(build, "troubleshoot_box"));
  GtkWidget *installationbox =GTK_WIDGET(gtk_builder_get_object(build, "installation_box"));
  gtk_widget_set_name(learnbox, "learn_box");
  gtk_widget_set_name(troublebox, "troubleshoot_box");
  gtk_widget_set_name(installationbox, "installation_box");

  GtkCssProvider *provider;
  GFile *cssfile;
  cssfile = g_file_new_for_path("./style.css");
  provider = gtk_css_provider_new();
  gtk_css_provider_load_from_file(provider,cssfile);
  gtk_style_context_add_provider_for_display(
        gdk_display_get_default(),
        GTK_STYLE_PROVIDER(provider),
        GTK_STYLE_PROVIDER_PRIORITY_USER
  );

  // search styling
  GtkWidget *search = GTK_WIDGET(gtk_builder_get_object(build,"search_label"));
  gtk_widget_set_name(search, "search_entry");

  GtkWidget *search_button = GTK_WIDGET(gtk_builder_get_object(build,"search_button"));
  gtk_widget_set_name(search_button, "search_button_one");

  // text styling
  GtkWidget *text1 = GTK_WIDGET(gtk_builder_get_object(build,"Gtk_label0"));
  GtkWidget *text2 = GTK_WIDGET(gtk_builder_get_object(build,"Gtk_label1"));
  gtk_widget_set_name(text1,"intro_text_one");
  gtk_widget_set_name(text2,"intro_text_two");



  g_object_unref(build);
  g_object_unref(cssfile);
  g_object_unref(provider);

  
}

int main(){
  GtkApplication *app;
  app = gtk_application_new("org.ubuntri.www", G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
  g_signal_connect(app, "startup", G_CALLBACK(startup), NULL);
  g_application_run(G_APPLICATION(app), 0, NULL);
  g_object_unref(app);

  return 0;
}